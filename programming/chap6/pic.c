/*************************************************************************
	> File Name: pic.c
	> Author: 
	> Mail: 
	> Created Time: 2017年08月12日 星期六 15时47分52秒
 ************************************************************************/

static int a;
extern int b;

extern void ext();

void bar()
{
    a=1;
    b=2;
}

void foo()
{
    bar();
    ext();
}
