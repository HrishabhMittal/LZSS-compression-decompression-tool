#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#if defined(_WIN32) || defined(_WIN64)
#else
#include <sys/stat.h>
#endif
typedef struct dirent DIRENTRY;
int mod(int num,int m) {
    return (num%m+m)%m;
}
