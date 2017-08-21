/*************************************************************************
	> File Name: crack.c
	> Author:
	> Mail:
	> Created Time: Mon 21 Aug 2017 04:20:46 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "1234567"
int verify_password (char *password)
{
	int authenticated;
	authenticated = strcmp(password, PASSWORD);
	return authenticated;
}
int main()
{
	int valid_flag = 0;
	char password[1024];
	while (1)
	{
		printf("please input password:");
		scanf("%s", password);
		valid_flag = verify_password(password);
		if (valid_flag)
		{
			printf("incorrect password!\n\n");
		}
		else
		{
			printf("Congratulation! You have passed the verification!\n");
			break;
		}
	}
	return 0;
}
