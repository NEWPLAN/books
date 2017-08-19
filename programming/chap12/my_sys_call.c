/*************************************************************************
	> File Name: my_sys_call.c
	> Author: 
	> Mail: 
	> Created Time: Wed 16 Aug 2017 11:03:18 AM CST
 ************************************************************************/
//must run at 32 bit 
//gcc -m32 my_sys_call.c -o my_sys_call
int main(int argc, char** argv)
{
    int ret;
    char msg[]="hello, world!\n";
    __asm__ volatile ("call *%%esi"
            : "=a" (ret)
            : "a" (4),
            "S" (0xffffe400),
            "b" ((long)1),
            "c" ((long)msg),
            "d" ((long)sizeof(msg))
            );
    return 0;
}
