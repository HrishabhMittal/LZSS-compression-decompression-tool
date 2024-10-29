#pragma once
#include "bits.c"
#include "files.c"
int decompressfile(char* in,char* out) {
    file f;
    file_construct(&f);
    rbits rb;
    rbits_file_construct(&rb,in);
    while (!rbits_eof(&rb)) {
        if (rbits_readbit(&rb)) {
            int num=rbits_get(&rb,4);
            if (rbits_bits_left(&rb)<12) break;
            int index=f.size-rbits_get(&rb,12);
            for (int i=0;i<num;i++) {
                file_addc(&f,f.data[index++]);
            }
        } else {
            if (rbits_bits_left(&rb)<7) break;
            file_addc(&f,rbits_get(&rb,8));
        }
    }
    FILE* ff=fopen(out,"wb");
    for (int i=0;i<f.size-1;i++) {
        fprintf(ff,"%c",f.data[i]);
    }
    fclose(ff);
    return EXIT_SUCCESS;
}