#include "string.c"
int comparefile(char* p1,char* p2) {
    FILE* f1=fopen(p1,"rb");
    FILE* f2=fopen(p2,"rb");
    if (f1==NULL && f1==NULL) return 1;
    if (f1==NULL || f2==NULL) return 0;
    while (!feof(f1)) {
        if (feof(f2)) return 0;
        if (fgetc(f1)!=fgetc(f2)) return 0;
    }
    return feof(f1)==feof(f2);
}
int comparedir(char* path1,char* path2) {
    DIR *dir1,*dir2;
    DIRENTRY *ent1,*ent2;
    if ((dir1=opendir(path1))!=NULL) {
        if ((dir2=opendir(path2))==NULL) return 0;
        while ((ent1=readdir(dir1))!=NULL) {
            if ((ent2=readdir(dir2))==NULL) return 0;
            if (strequal(".",ent1->d_name) || strequal("..",ent1->d_name)) {
                continue;
            } else {
                if (!strequal(ent1->d_name,ent2->d_name)) return 0;
                char *comp,*cur,*add;
                strconcat(&add,"/",ent1->d_name);
                strconcat(&comp,path1,add);
                strconcat(&cur,path2,add);
                if (!comparedir(comp,cur)) {
                    return 0;
                };
                free(comp);
                free(cur);
                free(add);
            }
        }
        closedir(dir1);
        closedir(dir2);
    } else {
        return comparefile(path1,path2);
    }
    return 1;
}