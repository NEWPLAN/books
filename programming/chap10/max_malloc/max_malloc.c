/*************************************************************************
	> File Name: max_malloc.c
	> Author: 
	> Mail: 
	> Created Time: Tue 15 Aug 2017 02:11:47 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int unit[]={1024*1024,1024,1};
    unsigned long long all=0,index=0;
    for(index=0;index<sizeof(unit)/sizeof(unit[0]);index++)
    {
        int flags=1;
        while(flags)
        {
            
             char* p=(char*)malloc(sizeof(char)*unit[index]+all);
            if(p)
            {
                all+=unit[index];
                free(p);
    		}
    		else
    			flags=0;
		}
	}
	printf("max malloc: %fGB, %fMB, %lluByte\n",all/1024.0/1024/1024,all/1024.0/1024,all);
	while(1);
	return 0;
}
