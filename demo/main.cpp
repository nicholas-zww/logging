
#include "logger.h"

int main()
{
    int i = 0;
    for (i = 0; i < 1000; i++) {
        LOG("this is a test");
    }
    return 0;
}
