/**********************************************************
 * Author        : yxmsw2007
 * Email         : yxmsw2007@gmail.com
 * Last modified : 2015-05-24 23:20
 * Filename      : fseek_ftell.c
 * Description   : 
 * *******************************************************/
#include <stdio.h>

int main(int argc, char* argv[]) {
    long len;
    FILE *fp;

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        printf("not open!");
        return 0;
    }
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    fclose(fp);
    printf("len = %ld\n", len);
    return 0;
}
