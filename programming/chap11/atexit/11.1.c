/*************************************************************************
	> File Name: 11.1.c
	> Author: 
	> Mail: 
	> Created Time: Tue 15 Aug 2017 03:02:56 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
void foo()
{
    printf("bye\n");
}

int main()
{
    atexit(&foo);
    printf("endof main\n");
    return 0;
}
