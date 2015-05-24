/**********************************************************
 * Author        : yxmsw2007
 * Email         : yxmsw2007@gmail.com
 * Last modified : 2015-05-24 23:19
 * Filename      : fread_fwrite.c
 * Description   : 
 * *******************************************************/
#include <stdio.h>

int main(int argc, char* argv[]) {
    struct stu { /* 定义结构体类型 */ 
        char name[15];
        char num[6];
        float score[2];
    } student; /* 说明结构体变量 */ 

    FILE *fp;

    if ((fp = fopen(argv[1], "wb+")) == NULL) { /* 以二进制读写方式打开文件 */ 
        printf("not open %s!", argv[1]);
        return 0;
    }
    int i; /* 在循环条件中声明变量的话，只在C99标准中支持，C90标准不支持 */ 
    for (i = 0; i < 2; i++) {
        scanf("%s %s %f %f", student.name, student.num,
                &student.score[0], &student.score[1]); /* 从键盘键入 */ 
        fwrite(&student, sizeof(student), 1, fp);
    }
    for (i = 0; i < 2; i++) {
        fread(&student, sizeof(student), 1, fp);
        printf("%s %s %7.2f %7.2f\n", student.name, student.num, 
                student.score[0], student.score[1]); /* 显示到屏幕 */ 
    }
    fclose(fp);
    return 0;
}
