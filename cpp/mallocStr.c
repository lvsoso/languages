#define _CRT_SECURE_NO_WARNINGS
#include "mallocStr.h"
char * func(int size, char *str)
{
    char* p = (char *)malloc(size);
    strcpy(p, str);
    return p;
}
