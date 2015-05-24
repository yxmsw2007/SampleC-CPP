/**********************************************************
 * Author        : yxmsw2007
 * Email         : yxmsw2007@gmail.com
 * Last modified : 2015-05-24 23:20
 * Filename      : fscanf_fprintf.c
 * Description   : 
 * *******************************************************/
#include <stdio.h>

/*
将一些格式化的数据写入文本文件，再从该文件中医格式化方法读出显示在屏幕上，
其格式化数据是两个学生记录，包括姓名、学号、两科成绩。
 * */ 

int main(int argc, char* argv[]) {
    struct stu { /* 定义结构体类型 */ 
        char name[15];
        char num[6];
        float score[2];
    } student; /* 说明结构体变量 */ 

    FILE *fp;

    if ((fp = fopen(argv[1], "w")) == NULL) {
        printf("not open %s!", argv[1]);
        return 0;
    }
    int i; /* 在循环条件中声明变量的话，只在C99标准中支持，C90标准不支持 */ 
    for (i = 0; i < 2; i++) {
        scanf("%s %s %f %f", student.name, student.num,
                &student.score[0], &student.score[1]); /* 从键盘键入 */ 
        fprintf(fp, "%s %s %7.2f %7.2f\n", student.name, 
                student.num, student.score[0], student.score[1]); /* 写入文件 */ 
    }
    while(fscanf(fp, "%s %s %f %f\n", student.name, student.num, 
                &student.score[0], &student.score[1]) != EOF) {
        printf("%s %s %7.2f %7.2f\n", student.name, student.num, 
                student.score[0], student.score[1]); /* 显示到屏幕 */ 
    }
    fclose(fp);
    return 0;
}
