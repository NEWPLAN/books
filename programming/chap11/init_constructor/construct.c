/*************************************************************************
	> File Name: construct.c
	> Author: 
	> Mail: 
	> Created Time: 2017年08月15日 星期二 22时33分26秒
 ************************************************************************/

#include<stdio.h>
void my_init(void)
{
    printf("hello, ");
}

typedef void (*ctor_t)(void);

ctor_t __attribute__((section(".ctors"))) my_init_p=&my_init;

int main(int argc, char** argv)
{
    printf("world!\n");
    return 0;
}
