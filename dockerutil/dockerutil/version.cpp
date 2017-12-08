#include "dockerutil.h"

int PrintVersion(ArgumentStream* Arguments)
{
    fprintf(stdout, "dockerutil %s\n", DOCKERUTIL_VERSION);

    return ERROR_SUCCESS;
}