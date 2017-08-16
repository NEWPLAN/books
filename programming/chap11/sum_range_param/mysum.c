/*************************************************************************
	> File Name: mysum.c
	> Author: 
	> Mail: 
	> Created Time: Tue 15 Aug 2017 05:06:08 PM CST
 ************************************************************************/

#include<stdio.h>
int sum(unsigned int num,...)
{
    int *p=&num+1;
    int ret=0;
    while(num--)
    {
        ret+=*p++;
    }
    return ret;
}

int main(int argc, char** argv)
{
    int res=0;
    res=sum(6,1,2,3,4,5,6);
    printf("%d\n",res);
    return 0;
}
