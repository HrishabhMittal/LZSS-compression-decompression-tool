#pragma once
#include "include.h"
typedef struct {
    char* data;
    int size;
    int cap;
} file;
void file_construct(file * f) {
    f->data=(char*)malloc(16);
    f->data[0]=0;
    f->cap=16;
    f->size=0;
}
void file_addc(file*f,char c) {
    if (f->size>=f->cap) {
        f->cap*=2;
        f->data=(char*)realloc(f->data,f->cap);
    }
    f->data[f->size]=c;
    f->data[++f->size]=0;
}
void loadfile(file* f,char* name) {
    FILE* file=fopen(name,"rb");
    if (file==NULL) exit(1);
    int cap=16;
    f->data=(char*)malloc(cap);
    f->size=0;
    while (!feof(file)) {
        char c=fgetc(file);
        if (f->size>=cap) {
            cap*=2;
            f->data=(char*)realloc(f->data,cap);
        }
        f->data[f->size++]=c;
    }
    f->size--;
    f->data[f->size]=0;
    fclose(file);
}
void match(file* f,int i,int j,int* result) {
    int num=-1;
    int pos=-1;
    if (i<0 || i>=j || j>=f->size) {
        result[0]=-1;
        result[1]=-1;
        return;
    }
    int k=i;
    while (k<j) {
        int ind=0;
        while (j+ind<f->size && f->data[(k+mod(ind,(j-k)))]==f->data[j+ind]) ind++;
        if (ind>=num) {
            num=ind;
            pos=k;
        }
        k++;
    }
    if (num>15) num=15;
    pos=j-pos;
    result[0]=num;
    result[1]=pos;
}
void file_deconstruct(file*f) {
    free(f->data);
    f->data=NULL;
    f->size=0;
}
