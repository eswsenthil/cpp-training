//
//  main.cpp
//  TestStrncmp
//
//  Created by Eswaran, Senthilkumar on 31.5.2022.
//

#include <iostream>

#include <sys/sysctl.h>

static
int getSystemInfo(int *errnum, const char *name, void *outputBuffer, size_t *outputSize)
{
    int ret = sysctlbyname(name, outputBuffer, outputSize, NULL, 0);
    if (ret != 0)
    {
        *errnum = errno;
    }
    return ret;
}


bool isCpuVendorNameBeginsWith(const char* inVendorName)
{
    bool isExpectedVendor = false;
    
    //
    // Presently at:
    //   M1 Macbook Pro - one machine has:
    //    machdep.cpu.brand_string: Apple M1
    //   Developer Tool Kit macmini had:
    //     machdep.cpu.brand_string: Apple processor
    //   Intel - one machine has:
    //     machdep.cpu.brand_string: Intel(R) Core(TM) i7-8850H CPU @ 2.60GHz
    // So, the 128 size should be ok.
    //
    char brandName[128];
    size_t len = sizeof(brandName) -1;
    int errnum = 0;
    int ret = getSystemInfo(&errnum, "machdep.cpu.brand_string", &brandName, &len);
    if (ret == 0 || errnum == ENOMEM)
    {
        brandName[sizeof(brandName)-1] = 0;
        int cmp = strncmp(brandName, inVendorName, strlen(inVendorName));
        if (0 == cmp)
        {
            isExpectedVendor = true;
        }
    }
    return isExpectedVendor;
}

void testStrncmp()
{
    if (isCpuVendorNameBeginsWith("Apple")) {
        std::cout << "This is Apple" << std::endl;
    }
    else {
        std::cout << "This is Not Apple" << std::endl;
    }
    
    if (isCpuVendorNameBeginsWith("Intel(R)")) {
        std::cout << "This is Intel" << std::endl;
    }
    else {
        std::cout << "This is Not Intel" << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    testStrncmp();
    return 0;
}
