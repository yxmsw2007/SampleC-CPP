#include <stdio.h>

int main(int argc, char* argv[]) {
    char ch;
    FILE *fp, *fp2;

    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("not open!");
        return 0;
    }
    if ((fp2 = fopen(argv[2], "w")) == NULL) {
        printf("not open fp2!");
        return 0;
    }
    while((ch = fgetc(fp)) != EOF) {
        putchar(ch); 
        fputc(ch, fp2);
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}
