
// version/architecture scan
//,
//,
//,
#include <iostream>
#include <comdef.h>
#include <WbemIdl.h>

#pragma comment(lib, "wbemuuid.lib")

void QueryOperatingSystemInfo(IWbemServices* pSvc);
void QueryInstalledSoftware(IWbemServices* pSvc);

int main() {
    HRESULT hres;

    
    hres = CoInitializeEx(0, COINIT_MULTITHREADED);
    if (FAILED(hres)) {
        std::cerr << "Failed to initialize COM library. Error code: " << hres << std::endl;
        return 1;
    }

    
    hres = CoInitializeSecurity(
        NULL,
        -1,
        NULL,
        NULL,
        RPC_C_AUTHN_LEVEL_DEFAULT,
        RPC_C_IMP_LEVEL_IMPERSONATE,
        NULL,
        EOAC_NONE,
        NULL
    );

    if (FAILED(hres)) {
        std::cerr << "Failed to initialize security. Error code: " << hres << std::endl;
        CoUninitialize();
        return 1;
    }

    
    IWbemLocator* pLoc = NULL;
    hres = CoCreateInstance(
        CLSID_WbemLocator,
        0,
        CLSCTX_INPROC_SERVER,
        IID_IWbemLocator,
        (LPVOID*)&pLoc
    );

    if (FAILED(hres)) {
        std::cerr << "Failed to create IWbemLocator object. Error code: " << hres << std::endl;
        CoUninitialize();
        return 1;
    }

    
    IWbemServices* pSvc = NULL;
    hres = pLoc->ConnectServer(
        _bstr_t(L"ROOT\\CIMV2"),
        NULL,
        NULL,
        0,
        NULL,
        0,
        0,
        &pSvc
    );

    if (FAILED(hres)) {
        std::cerr << "Failed to connect to WMI namespace. Error code: " << hres << std::endl;
        pLoc->Release();
        CoUninitialize();
        return 1;
    }

    
    hres = CoSetProxyBlanket(
        pSvc,
        RPC_C_AUTHN_WINNT,
        RPC_C_AUTHZ_NONE,
        NULL,
        RPC_C_AUTHN_LEVEL_CALL,
        RPC_C_IMP_LEVEL_IMPERSONATE,
        NULL,
        EOAC_NONE
    );

    if (FAILED(hres)) {
        std::cerr << "Failed to set proxy blanket. Error code: " << hres << std::endl;
        pSvc->Release();
        pLoc->Release();
        CoUninitialize();
        return 1;
    }

    
    QueryOperatingSystemInfo(pSvc);

    
    QueryInstalledSoftware(pSvc);

    
    pSvc->Release();
    pLoc->Release();
    CoUninitialize();

    std::cout << "enter to exit...";
    getchar(); 

    return 0;
}

void QueryOperatingSystemInfo(IWbemServices* pSvc) {
    
    IEnumWbemClassObject* pEnumeratorOS = NULL;
    HRESULT hres = pSvc->ExecQuery(
        _bstr_t("WQL"),
        _bstr_t("SELECT * FROM Win32_OperatingSystem"),
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
        NULL,
        &pEnumeratorOS
    );

    if (SUCCEEDED(hres)) {
        IWbemClassObject* pclsObjOS = NULL;
        ULONG uReturnOS = 0;

        std::cout << "Operating System Information:\n";

        while (pEnumeratorOS) {
            HRESULT hrOS = pEnumeratorOS->Next(WBEM_INFINITE, 1, &pclsObjOS, &uReturnOS);

            if (uReturnOS == 0 || FAILED(hrOS)) {
                break;
            }

            VARIANT vtPropOS;
            hrOS = pclsObjOS->Get(L"Caption", 0, &vtPropOS, 0, 0);

            if (SUCCEEDED(hrOS)) {
                std::wcout << L"- " << vtPropOS.bstrVal << std::endl;
                VariantClear(&vtPropOS);
            }

            pclsObjOS->Release();
        }

        pEnumeratorOS->Release();
    }
}

void QueryInstalledSoftware(IWbemServices* pSvc) {
    
    IEnumWbemClassObject* pEnumeratorSW = NULL;
    HRESULT hres = pSvc->ExecQuery(
        _bstr_t("WQL"),
        _bstr_t("SELECT * FROM Win32_Product"),
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
        NULL,
        &pEnumeratorSW
    );

    if (SUCCEEDED(hres)) {
        IWbemClassObject* pclsObjSW = NULL;
        ULONG uReturnSW = 0;

        std::cout << "\nInstalled Software:\n";

        while (pEnumeratorSW) {
            HRESULT hrSW = pEnumeratorSW->Next(WBEM_INFINITE, 1, &pclsObjSW, &uReturnSW);

            if (uReturnSW == 0 || FAILED(hrSW)) {
                break;
            }

            VARIANT vtPropSW;
            hrSW = pclsObjSW->Get(L"Name", 0, &vtPropSW, 0, 0);

            if (SUCCEEDED(hrSW)) {
                std::wcout << L"- " << vtPropSW.bstrVal << std::endl;
                VariantClear(&vtPropSW);
            }

            pclsObjSW->Release();
        }

        pEnumeratorSW->Release();
    }
}
