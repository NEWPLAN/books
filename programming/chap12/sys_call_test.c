/*************************************************************************
	> File Name: sys_call_test.c
	> Author: 
	> Mail: 
	> Created Time: Wed 16 Aug 2017 09:27:32 AM CST
 ************************************************************************/

#include <unistd.h>

int main(int argc, char** argv)
{
    char buffer[64];
    char* error_msg="open file error\n";
    char* success_msg="open file success\n";
    char* filename=NULL;
    if(argc>=2)
        filename=argv[1];
    else
        filename="readme.txt";
    int fd=open(filename,0,0);
    if(fd==-1)
    {
        write(0,error_msg,strlen(error_msg));
        return -1;
    }
    write(0,success_msg,strlen(success_msg));

    read(fd,buffer,64);
    close(fd);
    return 0;
}
