#pragma once
#include "include.h"
int strsize(const char* str) {
    int i=0;
    for (int i=0;str[i]!=0;i++);
    return i;
}
int strequal(const char* c1,const char* c2) {
    int i=0;
    for (;c1[i]!=0;i++) {
        if (c1[i]!=c2[i]) return 0;
    }
    if (c2[i]==0) return 1;
    return 0;
}
int strconcat(char** res,const char* c1,const char* c2) {
    int i=0,j=0;
    for (;c1[i]!=0;i++);
    for (;c2[j]!=0;j++);
    *res=(char*)malloc(i+j+1);
    for (int k=0;k<i;k++) {
        (*res)[k]=c1[k];
    }
    for (int k=0;k<=j;k++) {
        (*res)[i+k]=c2[k];
    }
    return 1;
}