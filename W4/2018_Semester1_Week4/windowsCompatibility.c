#include "windowsCompatibility.h"

void enableWindowsCompatibility()
{
    /* Disable buffering on stdout - this is typically an issue when using Eclipse on Windows. */
    setbuf(stdout, NULL);

    /* Disable buffering on stderr just in case. */
    setbuf(stderr, NULL);
}
