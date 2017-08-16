#include <stdio.h>

int main(int argc, char** argv)
{
    FILE* fp=stdout;
    printf("%d\n%d\n%s\n%s\n",fp->_fileno,fp->_flags2,fp->_IO_backup_base,fp->_IO_buf_base);
    return 0;
}
