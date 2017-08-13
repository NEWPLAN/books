/*************************************************************************
	> File Name: ManualNameMangling.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 31 Jul 2017 03:11:34 PM CST
 ************************************************************************/


#include <stdio.h>
namespace myname{

	double var = 42;

}



extern "C" __attribute__((weak)) double _ZN6myname3varE;



int main(int argc, char** argv)
{

	printf("%d\n", _ZN6myname3varE);

	return 0;

}
