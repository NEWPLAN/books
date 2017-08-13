/*************************************************************************
	> File Name: TinyHelloWorld.c
	> Author: 
	> Mail: 
	> Created Time: Thu 03 Aug 2017 11:43:29 AM CST
 ************************************************************************/

char* str="Hello world!\n";

void print(void)
{
    asm("movl $13, %%edx \n\t"
        "movl %0, %%ecx \n\t"
        "movl $0, %%ebx \n\t"
        "movl $4, %%eax \n\t"
        "int $0x80    \n\t"
        ::"r"(str):"edx","ecx","ebx"
            );
}

void exit(void)
{
    asm(
            "movl $42, %ebx \n\t"
            "movl $1, %eax \n\t"
            "int $0x80  \n\t"
       );
}

void nomain(void)
{
    print();
    exit();
}
