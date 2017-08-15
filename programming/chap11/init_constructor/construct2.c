/*************************************************************************
	> File Name: construct.c
	> Author: 
	> Mail: 
	> Created Time: 2017年08月15日 星期二 22时33分26秒
 ************************************************************************/

#include<stdio.h>

void my_init(void) __attribute__((constructor));
void my_init(void)
{
    printf("hello, ");
}



int main(int argc, char** argv)
{
    printf("world!\n");
    return 0;
}
