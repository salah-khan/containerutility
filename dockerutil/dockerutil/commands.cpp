#include "dockerutil.h"

COMMAND ParseCommand(ArgumentStream* Arguments)
{
    char* commandArgument = Arguments->GetArgument();

    if (commandArgument == nullptr) {
        return COMMAND_INVALID;
    }

    Arguments->Advance();

    if (_stricmp(commandArgument, "getaccountsid") == 0) {
        return COMMAND_GETACCOUNTSID;
    }
    if (_stricmp(commandArgument, "--version") == 0) {
        return COMMAND_VERSION;
    }

    return COMMAND_INVALID;
}