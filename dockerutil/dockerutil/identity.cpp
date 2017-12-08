#include "dockerutil.h"

int GetAccountSid(ArgumentStream* Arguments)
{
    char* accountName = Arguments->GetArgument();

    if (accountName == nullptr) {
        fprintf(stderr, "Usage:  docker getaccountsid accountname\n\n");
        return ERROR_INVALID_PARAMETER;
    }

    Arguments->Advance();

    PSID sid = (PSID) new char[MAX_SID_SIZE];
    LPTSTR referencedDomain = (LPTSTR) new char[MAX_PATH];
    DWORD sidLength = MAX_SID_SIZE;
    DWORD referencedDomainLength = MAX_PATH;
    SID_NAME_USE sidNameUse;

    if (LookupAccountName(nullptr, accountName, sid, &sidLength, referencedDomain, &referencedDomainLength, &sidNameUse) == false) {
        LPTSTR messageBuffer;

        FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            nullptr, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

        fprintf(stderr, "%s\n", messageBuffer);

        delete[] sid;
        delete[] referencedDomain;

        return GetLastError();
    }

    LPTSTR stringSid = nullptr;

    if (ConvertSidToStringSid(sid, &stringSid) != false) {
        fprintf(stdout, "%s", stringSid);
        LocalFree(stringSid);

    } else {
        LPTSTR messageBuffer;

        FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            nullptr, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

        fprintf(stderr, "%s\n", messageBuffer);

        delete[] sid;
        delete[] referencedDomain;
        return GetLastError();
    }

    delete[] sid;
    delete[] referencedDomain;

    return ERROR_SUCCESS;
}