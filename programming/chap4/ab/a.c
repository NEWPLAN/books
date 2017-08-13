/*************************************************************************
	> File Name: a.c
	> Author: 
	> Mail: 
	> Created Time: Mon 31 Jul 2017 03:42:17 PM CST
 ************************************************************************/

extern int shared;

int main(int argc, char** argv)
{
    int a=100;
    swap(&a,&shared);
    return 0;
}
