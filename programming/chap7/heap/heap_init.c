/*************************************************************************
	> File Name: heap_init.c
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Aug 2017 02:35:27 PM CST
 ************************************************************************/

#include<stdio.h>
#include <elf.h>

int main(int argc, char** argv)
{
    int *p=(int*) argv;
    int i;
    Elf32_auxv_t * aux;

    printf("argument count: %d\n",*(p-1));
    for(i=0;i<*(p-1);i++)
    {
        printf("Argument %d : %s\n",i,*(p+i));
        //p++;
    }
    p+=i;
    p++;
    printf("\n\nEnvironment:\n");
    while(*p)
    {
        printf("%s\n",*p);
        p++;
    }

    p++;

    printf("\n\nAuxiliary Vectors:\n");
    aux=(Elf32_auxv_t*)p;
    while(aux->a_type!=AT_NULL)
    {
        printf("Type: %02d Value: %x\n",aux->a_type,aux->a_un.a_val);
        aux++;
    }
    return 0;
}
