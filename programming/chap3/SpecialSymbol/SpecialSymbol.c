/*************************************************************************
	> File Name: SpecialSymbol.c
	> Author: 
	> Mail: 
	> Created Time: Mon 31 Jul 2017 02:18:54 PM CST
 ************************************************************************/

#include<stdio.h>

extern char __executable_start[];/*程序起始地址,不是入口地址，入口地址是main所在的位置*/
extern char etext[],_etext[],__etext[];/*代码段结束地址*/
extern char edata[],_edata[];/*数据段结束地址*/
extern char end[],_end[];/*程序结束地址*/

int main(int argc, char** argv)
{
    printf("Executable Start at %X\n",__executable_start);
    printf("Text End %X %X %X\n",etext,_etext,__etext);
    printf("Data End %X %X\n",edata,_edata);
    printf("Executable End at %X %X\n",end,_end);
    return 0;
}
