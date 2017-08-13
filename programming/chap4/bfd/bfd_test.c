/*************************************************************************
	> File Name: bfd_test.c
	> Author: 
	> Mail: 
	> Created Time: Thu 03 Aug 2017 06:25:15 PM CST
 ************************************************************************/

#include<stdio.h>
#include <bfd.h>

int main(int argc, char** argv)
{
    const char** t=bfd_target_list();
    while(*t)
    {
        printf("%s\n",*t++);
    }
    return 0;
}
