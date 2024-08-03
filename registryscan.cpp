#include <iostream>
#include <vector>
#include <string>
#include <windows.h>


bool DoesRegistryKeyExist(HKEY hRootKey, const std::wstring& subkeyPath) {
    HKEY hKey;
    if (RegOpenKeyExW(hRootKey, subkeyPath.c_str(), 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return true; 
    }
    return false; 
}

int main() {
    
    HKEY hRootKey = HKEY_LOCAL_MACHINE;

    
    std::vector<std::wstring> registryKeys;

    
    registryKeys.push_back(L"SYSTEM\\CurrentControlSet\\Services");
    registryKeys.push_back(L"SYSTEM\\CurrentControlSet\\Control\\SecurityProviders");
    registryKeys.push_back(L"SYSTEM\\CurrentControlSet\\Control\\SafeBoot");
    registryKeys.push_back(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options");
    registryKeys.push_back(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon");
    registryKeys.push_back(L"SOFTWARE\\Microsoft\\Security Manager");
    registryKeys.push_back(L"SOFTWARE\\Microsoft\\Security Center");
    registryKeys.push_back(L"SOFTWARE\\Microsoft\\Windows Defender");
    registryKeys.push_back(L"SOFTWARE\\Symantec");
    registryKeys.push_back(L"SOFTWARE\\McAfee");
    registryKeys.push_back(L"SOFTWARE\\KasperskyLab:");
    registryKeys.push_back(L"SOFTWARE\\ESET");
    registryKeys.push_back(L"SOFTWARE\\TrendMicro");
    registryKeys.push_back(L"SOFTWARE\\AVG");
    registryKeys.push_back(L"SOFTWARE\\Avast Software");
    registryKeys.push_back(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce");
    registryKeys.push_back(L"SOFTWARE\\Microsoft\\Virtual Machine");
    registryKeys.push_back(L"SYSTEM\\CurrentControlSet\\Services");
    registryKeys.push_back(L"SYSTEM\\CurrentControlSet\\Services\\SharedAccess\\Parameters\\FirewallPolicy");
    registryKeys.push_back(L"SYSTEM\\CurrentControlSet\\Services\\MpsSvc");
    // add more keys as needed

    
    for (const std::wstring& key : registryKeys) {
        if (DoesRegistryKeyExist(hRootKey, key)) {
            std::wcout << L"Key '" << key << L"' exists." << std::endl;
        }
        else {
            std::wcout << L"Key '" << key << L"' does not exist." << std::endl;
        }
    }

    
    std::wcout << L"Press any key to exit..." << std::endl;
    std::wcin.get();  

    return 0;
}
