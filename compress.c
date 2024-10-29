#include "files.c"
#include "bits.c"
int compressfile(char* in,char* out) {
    file f;
    bits b;
    bits_construct(&b);
    loadfile(&f,in);
    int search=0;
    for (int i=0;i<f.size;i++) {
        int result[2];
        if (i-search>4095) {
            search=i-4095;
        }
        match(&f,search,i,result);
        if (result[0]>1) {
            bits_addbit(&b,1);
            bits_addbits(&b,result[0],4);
            bits_addbits(&b,result[1],12);
            i+=(result[0]-1);
        } else {
            bits_addbit(&b,0);
            bits_addbits(&b,f.data[i],8);
        }
    }
    FILE* file=fopen(out,"wb");
    int size=mod(b.size,8)==0?b.size/8:(b.size/8+1);
    for (int i=0;i<size;i++) {
        fprintf(file,"%c",b.start[i]);
    }
    fclose(file);
    bits_deconstruct(&b);
    file_deconstruct(&f);
    return EXIT_SUCCESS;
}
