//
//  main.cpp
//  DemoPointers
//
//

#include <iostream>

typedef struct
{
    int heightInCm;
    double weightInKg;
    char initial;
    char name[8];
} Boy;


class Person
{
private:
    int mHeightInCm;
    double mWeightInKg;
    
public:
    Person(int heightInCm, double weightInKg):
    mHeightInCm(heightInCm),
    mWeightInKg(weightInKg)
    {
    }
};
Person person(160, 70.5);

void demoBasicPointerDereference()
{
    int heightInCentiMetres = 160;
    
    printf("Height is:%d cms.\n\n", heightInCentiMetres);
    
    int *pHeight = &heightInCentiMetres;
    
    printf("Address of value of heightInCentiMetres is:%p.\n\n", pHeight);
    
    printf("Height is:%d cms.\n\n", *pHeight);
    
    double weightInKilograms = 70.5;
    
    printf("Weight is:%f kgs.\n\n", weightInKilograms);
    
    double *pWeight = &weightInKilograms;
    
    printf("Address of value of weightInKilograms is:%p.\n\n", pWeight);
    
    printf("Weight is:%f kgs.\n\n", *pWeight);
    
    char initial = 'A';
    
    printf("Initial is:%c.\n\n", initial);

    char *pInitial = &initial;
    
    printf("Address of value of initial is:%p.\n\n", pInitial);
    
    printf("Initial is:%c.\n\n", *pInitial);
    
    char name[] = { "Boban" };
    
    printf("Name is:%s.\n\n", name);
    
    char *pName = name;
    
    printf("Address of value of name is:%p.\n\n", pName);
    
    printf("Name is:%s.\n\n", pName);
    
}

void demoDereferenceStructPointers()
{
    Boy boy = { 160, 70.5, 'A', "Boban" };

    puts("Boy's details:");
    printf("Name: %c. %s\n", boy.initial, boy.name);
    printf("Height: %d cms\n", boy.heightInCm);
    printf("Weight: %f kgs\n\n", boy.weightInKg);
    
    Boy *pBoy = &boy;
    
    
    printf("Address of value of boy is: %p\n", pBoy);
    
    puts("Boy's details:");
    printf("Name: %c. %s\n", (*pBoy).initial, (*pBoy).name);
    printf("Height: %d cms\n", (*pBoy).heightInCm);
    printf("Weight: %f kgs\n\n", (*pBoy).weightInKg);
    
    // Note:
    // Dot(.) has higher order of precedence than Aseterisk(*).
    // Therefore the curved brackets are used to change the precedence.
}




void demoArrowUseStructPointers()
{
    Boy boy = { 160, 70.5, 'A', "Boban" };

    Boy *pBoy = &boy;
    
    puts("Boy's details:");
    printf("Name: %c. %s\n", (*pBoy).initial, (*pBoy).name);
    printf("Height: %d cms\n", (*pBoy).heightInCm);
    printf("Weight: %f kgs\n\n", (*pBoy).weightInKg);
    
    //
    // Use "PointerName->memberName" in place of "(*PointerName).memberName"
    //
    
    puts("Boy's details:");
    printf("Name: %c. %s\n", pBoy->initial, pBoy->name);
    printf("Height: %d cms\n", pBoy->heightInCm);
    printf("Weight: %f kgs\n\n", pBoy->weightInKg);
    
    printf("Address of value of boy.heightInCm is: %p\n", &pBoy->heightInCm);
 
    // -> has higher order of precedence over &.
}

void demoOtherTypes()
{
    float *pTemperatureInFarenheit;
    
    unsigned char* pTownName;
    
    wchar_t *pCityName;
    
    short *pShortInt;
    u_short *pUnsignedShort;
    long *pLongInt;
    unsigned *pUnsigned;
    long *pLong;
    long long *pLongLong;
    unsigned long long *pUnsignedLongLong;
    uint32_t *pUnsignedInt32;
    pid_t *pPid;
    size_t *pSize;
}



// Example of List Items:

// Continents:
// 1. Asia
// 2. Africa
// 3. Australia

// Oceans:
// a. Pacific
// b. Atlantic
// c. Indian



void demoUnionPointers()
{
    typedef union
    {
        int number;
        char name;
    } ListItem;
    
    ListItem listItem;
    
    listItem.name = 'a';
    
    printf("listItem Name: %c\n\n", listItem.name);
    
    ListItem *pListItem = &listItem;
    
    printf("listItem Name: %c\n\n", (*pListItem).name);
    
    printf("listItem Name: %c\n\n", pListItem->name);
    
    listItem.number = 1;
    
    printf("listItem Number: %d\n\n", listItem.number);
    
    printf("listItem Number: %d\n\n", (*pListItem).number);

    printf("listItem Number: %d\n\n", pListItem->number);

}

void demoPointersWithEnums()
{
    typedef enum
    {
        kSuccess = 0,
        kDenied = -1,
        kInvalid = -2
    } Result;
    
    Result result = kDenied;
    
    printf("Result is: %d\n\n", result);
    
    Result *pResult = &result;
    
    printf("Address of result is: %p\n\n", pResult);
    
    printf("Result is: %d\n", *pResult);
}

int getWeight(double *pWeight)
{
    *pWeight = 40.0;
    return 0;
}

void demoUseOfPointers()
{
    double weight;
    
    int result = getWeight(&weight);
    if (result == 0)
    {
        printf("Weight is:%f\n", weight);
    }
    else
    {
        printf("Weight could not be found\n");
    }
}

void demoSizeOfPointers()
{
    int x = 5;
    int y = 10;
    int *px = &x;
    
    printf("size of int is :%lu\n\n", sizeof(x));
    
    printf("size of int pointer is :%lu\n\n", sizeof(px));
    
    printf("Address of int is :%p\n\n", px);
    
    printf("Address of int pointer is :%p\n\n", &px);
}

bool isItemNameSameAsItemNumber(char itemName, int itemNum)
{
    int itemNameValue = tolower(itemName) - 'a' + 1;
    
    bool isLess = itemNameValue == itemNum;
    
    return isLess;
}

void demoFunctionPointers()
{
    // Need to use * within () to indicate it is a function pointer.
    // Otherwise, it will be treated as return type to the function.
    bool (*pItemComparator)(char, int) = isItemNameSameAsItemNumber;
    
    bool result = isItemNameSameAsItemNumber('a', 1);
    
    printf("a and 1 are %s\n\n", result ? "same" : "not same");
    
    result = pItemComparator('z', 26);
    
    printf("z and 26 are %s\n\n", result ? "same" : "not same");
    
    result = pItemComparator('b', 3);
    
    printf("b and 3 are %s\n\n", result ? "same" : "not same");
    
    // Declaring a Function pointer type
    typedef bool (*ItemComparator)(char, int);
    
    ItemComparator itemComparator = isItemNameSameAsItemNumber;
    
    result = itemComparator('b', 2);
    
    printf("b and 2 are %s\n\n", result ? "same" : "not same");
    
}

void demoMemoryAllocations()
{
    // For simple understanding, int pointer is chosen here.
    
    // Uninitialized pointer
    int *pRuns;
    
    // Allocates memory for 1 integer and
    // assigns the address of the allocated memory.
    pRuns = (int *)malloc(sizeof(int));
    
    *pRuns = 4;
    
    // Release Memory
    free(pRuns);
    
    // Pointer Initialized with NULL.
    // NULL is defined as 0.
    int *pRunsInAnOver = NULL;
    
    // Allocates memory for 6 integers and
    // assigns the address of the allocated memory.
    pRunsInAnOver = (int *)malloc(6 * sizeof(int));
    
    *pRunsInAnOver = 0;
    *(pRunsInAnOver+1) = 2;
    *(pRunsInAnOver+2) = 4;
    *(pRunsInAnOver+3) = 6;
    *(pRunsInAnOver+4) = 1;
    *(pRunsInAnOver+5) = 3;
    
    for (int ball = 0; ball < 6; ++ball)
    {
        //
        printf("Runs at ball %d is: %d\n", ball, *( pRunsInAnOver + ball ) );
    }
    
    pRunsInAnOver[0] = 6;
    pRunsInAnOver[1] = 4;
    pRunsInAnOver[2] = 6;
    pRunsInAnOver[3] = 4;
    pRunsInAnOver[4] = 6;
    pRunsInAnOver[5] = 4;
    
    for (int ball = 0; ball < 6; ++ball)
    {
        printf("Runs at ball %d is: %d\n", ball, pRunsInAnOver[ball]);
    }
    
    free(pRunsInAnOver);
}

int main(int argc, const char * argv[]) {
    
    // Begin - Covered on 26-Apr-2022
    
    //demoBasicPointerDereference();
    
    //demoUseOfPointers();
    
    // End - Covered on 26-Apr-2022
    
    // Begin - Covered on 28-Apr-2022
    
    //demoSizeOfPointers();
    
    //demoDereferenceStructPointers();
    
    //demoArrowUseStructPointers();
    
    //demoUnionPointers();
    
    // demoPointersWithEnums();
    
    // End - Covered on 28-Apr-2022
    
    demoFunctionPointers();
    
    demoMemoryAllocations();
    
    return 0;
}
