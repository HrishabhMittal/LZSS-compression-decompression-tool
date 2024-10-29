#pragma once
#include "include.h"
typedef struct {
    char* start;
    int size;
    int cap;
} bits;
void bits_construct(bits* b) {
    b->start=(char*)malloc(1);
    b->cap=8;
    b->size=0;
}
void bits_addbit(bits * b,int i) {
    if(b->size+1>=b->cap) {
        b->cap*=2;
        b->start=(char*)realloc(b->start,b->cap/8);
    }
    int floor=b->size/8;
    int fract=mod(b->size,8);
    char x=fract==0?0:b->start[floor];
    char nx=x+(mod(i,2)<<(7-fract));
    b->start[floor]=nx;
    b->size++;
}
void bits_addbits(bits*b,int num,int size) {
    for (int i=size-1;i>=0;i--) {
        bits_addbit(b,mod((num>>i),2));
    }
}
void bits_deconstruct(bits* b) {
    free(b->start);
    b->start=NULL;
    b->size=0;
    b->cap=0;
}

typedef struct {
    char* start;
    int size;
    int curr;
} rbits;
void rbits_construct(rbits* b,char* data) {
    int i=0;
    b->curr=0;
    for (;data[i]!=0;i++);
    b->start = (char*)malloc(i);
    for (int j=0;j<=i;j++) {
        b->start[j]=data[j];
    }
    b->size=i;
}
int rbits_eof(rbits* b) {
    if (b->curr/8>=b->size) return 1;
    else return 0;
}
int rbits_bits_left(rbits* b) {
    return b->size*8-b->curr;
}
void rbits_file_construct(rbits* b,char * filename) {
    FILE* f=fopen(filename,"rb");
    int cap=16;
    b->start=(char*)malloc(cap);
    b->size=0;
    b->curr=0;
    while (!feof(f)) {
        if (b->size>=cap) {
            cap*=2;
            b->start=(char*)realloc(b->start,cap);
        }
        b->start[b->size++]=fgetc(f);
    }
    b->start[b->size-1]=0;
    fclose(f);
}
int rbits_readbit(rbits* b) {
    if (rbits_eof(b)) return -1;
    int floor=b->curr/8;
    int fract=mod(b->curr,8);
    b->curr++;
    return mod((int)(b->start[floor])>>(7-fract),2);
}
int rbits_get(rbits* b,int num) {
    int out=0;
    for (int i=0;i<num;i++) {
        if (!rbits_eof(b)) out=(out<<1)+rbits_readbit(b);
        else return -1;
    };
    return out;
}
void rbits_deconstruct(rbits* b) {
    free(b->start);
    b->start=NULL;
    b->size=0;
    b->curr=0;
}