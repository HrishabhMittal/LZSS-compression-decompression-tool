#include "directories.c"
#include "compare.c"
int main(int argc,char**argv) {
    char* in=NULL;
    char* out=NULL;
    int mode=-1;
    for (int i=1;i<argc;i++) {
        if (strequal(argv[i],"-compare")) {
            int ans=1;
            while (i+2<argc) {
                ans&=comparedir(argv[i+1],argv[i+2]);
                i++;
            }
            if (ans) {
                printf("all fiiles/folders are identical");
            } else printf("all fiiles/folders are not identical");
            return 0;
        } else if (strequal(argv[i],"-c")) {
            if (mode==-1) mode=1;
            else {
                printf("multiple modes provided");
                return 1;
            }
        } else if (strequal(argv[i],"-d")) {
            if (mode==-1) mode=0;
            else {
                printf("multiple modes provided");
                exit(1);
            }
        } else if (strequal(argv[i],"-i")) {
            in=argv[++i];
        } else if (strequal(argv[i],"-o")) {
            out=argv[++i];
        } else {
            printf("wrong format");
            return 1;
        }
    }
    if (mode==-1) {
        printf("mode not specified");
        return 1;
    }
    if (in==NULL) {
        printf("no input provided");
        return 1;
    }
    if (out==NULL) {
        strconcat(&out,in,".comp");
        printf("output file assumed to be => %s",out);
    }
    if (mode) {
        compressdir(out,in);
    } else {
        decompressdir(out,in);
    }
    return 0;
}
