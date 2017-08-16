/*************************************************************************
	> File Name: test.c
	> Author:
	> Mail:
	> Created Time: Wed 16 Aug 2017 02:51:21 PM CST
 ************************************************************************/
#include "minicrt.h"


int main(long argc, char *argv[])
{
	long i;
	FILE* fp;

	fp	= fopen("test.txt", "w");

	//
	{
		char* buf = "hello how are you \n";
		long len = strlen(buf);
		fwrite(buf , 1, len, fp);
		write(0, "c", 1);
		printf("hello world\n");
		printf("%d  %s\n", len, buf);
	}

	fclose(fp);

	return 0;
}

