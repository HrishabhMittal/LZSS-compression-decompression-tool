#pragma once
#include "string.c"
#include "compress.c"
#include "decompress.c"
#if defined(_WIN32) || defined(_WIN64)
#define MODE
#else
#define MODE , 0777
#endif
void compressdir(char* comppath,char* curpath) {
    DIR* dir;
    DIRENTRY* ent;
    if ((dir=opendir(curpath))!=NULL) {
        mkdir(comppath MODE);
        while ((ent=readdir(dir))!=NULL) {
            if (strequal(".",ent->d_name) || strequal("..",ent->d_name)) {
                continue;
            } else {
                char*comp,*cur,*add;
                strconcat(&add,"/",ent->d_name);
                strconcat(&comp,comppath,add);
                strconcat(&cur,curpath,add);
                compressdir(comp,cur);
                free(comp);
                free(cur);
                free(add);
            }
        }
        closedir(dir);
    } else {
        compressfile(curpath,comppath);
    }
}
void decompressdir(char* decomppath,char* curpath) {
    DIR* dir;
    DIRENTRY* ent;
    if ((dir=opendir(curpath))!=NULL) {
        mkdir(decomppath MODE);
        while ((ent=readdir(dir))!=NULL) {
            if (strequal(".",ent->d_name) || strequal("..",ent->d_name)) {
                continue;
            } else {
                char*comp,*cur,*add;
                strconcat(&add,"/",ent->d_name);
                strconcat(&comp,decomppath,add);
                strconcat(&cur,curpath,add);
                decompressdir(comp,cur);
                free(comp);
                free(cur);
                free(add);
            }
        }
        closedir(dir);
    } else {
        decompressfile(curpath,decomppath);
    }
}
