#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

// Function to check if a registry key exists
bool DoesRegistryKeyExist(HKEY hRootKey, const std::wstring& subkeyPath) {
    HKEY hKey;
    if (RegOpenKeyExW(hRootKey, subkeyPath.c_str(), 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return true; // Key exists
    }
    return false; // Key does not exist
}

int main() {
    // Root registry key (e.g., HKEY_LOCAL_MACHINE)
    HKEY hRootKey = HKEY_LOCAL_MACHINE;

    // Create a vector to store the registry keys
    std::vector<std::wstring> registryKeys;

    // Add your registry keys to the list with wide character strings (wstring)
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

    // Add more keys as needed

    // Loop through the list and check the existence of each key
    for (const std::wstring& key : registryKeys) {
        if (DoesRegistryKeyExist(hRootKey, key)) {
            std::wcout << L"Key '" << key << L"' exists." << std::endl;
        }
        else {
            std::wcout << L"Key '" << key << L"' does not exist." << std::endl;
        }
    }

    // Pause to keep the command prompt window open
    std::wcout << L"Press any key to exit..." << std::endl;
    std::wcin.get();  // Wait for user input

    return 0;
}
