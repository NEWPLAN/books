/*************************************************************************
	> File Name: pthread.c
	> Author: 
	> Mail: 
	> Created Time: Mon 31 Jul 2017 03:31:14 PM CST
 ************************************************************************/

#include<stdio.h>

#include <pthread.h>

int pthread_create(
        pthread_t*,
        const pthread_attr_t*,
        void* (*)(void*),
        void*
        ) __attribute__((weak));

int main(int argc, char** argv)
{
    if(pthread_create)
    {
        printf("This is multi-thread version!\n");
    }
    else
    {
        printf("This is sigle-thread version\n");
    }
    return 0;
}
