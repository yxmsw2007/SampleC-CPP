/**********************************************************
 * Author        : yxmsw2007
 * Email         : yxmsw2007@gmail.com
 * Last modified : 2015-05-24 23:19
 * Filename      : fgets_fputs.c
 * Description   : 
 * *******************************************************/
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char str[128];

    FILE *fp1, *fp2;

    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        printf("not open %s!", argv[1]);
        return 0;
    }
    if ((fp2 = fopen(argv[2], "w")) == NULL) {
        printf("not open %s!", argv[2]);
        return 0;
    }
    while(fgets(str,128,fp1) != NULL) {
        fputs(str, fp2);    //从文件1读字符串并写入文件2
        printf("%d, %s", (int) strlen(str), str);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
