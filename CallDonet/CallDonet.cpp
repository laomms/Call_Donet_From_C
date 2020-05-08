#include <metahost.h>
#pragma comment(lib, "mscoree.lib")

int main()
{
    ICLRMetaHost* metaHost = NULL;
    ICLRRuntimeInfo* runtimeInfo = NULL;
    ICLRRuntimeHost* runtimeHost = NULL;

    if (CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, (LPVOID*)&metaHost) == S_OK)
        if (metaHost->GetRuntime(L"v4.0.30319", IID_ICLRRuntimeInfo, (LPVOID*)&runtimeInfo) == S_OK)
            if (runtimeInfo->GetInterface(CLSID_CLRRuntimeHost, IID_ICLRRuntimeHost, (LPVOID*)&runtimeHost) == S_OK)
                if (runtimeHost->Start() == S_OK)
                {
                    DWORD pReturnValue;
                    runtimeHost->ExecuteInDefaultAppDomain(L"D:\\HOOK\\CallDonet\\CLRHostLib\\bin\\Debug\\CLRHostLib.dll", L"CLRHostLib.ClrClass", L"ClrExcute", L"It works!!", &pReturnValue);

                    runtimeInfo->Release();
                    metaHost->Release();
                    runtimeHost->Release();
                }
    return 0;
}