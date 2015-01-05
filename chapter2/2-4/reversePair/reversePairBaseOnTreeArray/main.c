#include <stdio.h>
#include <stdlib.h>
#include "treeArray.h"
#include "reversePair.h"


int main(int argc, char const *argv[])
{
	int array[]={9,1,0,5,4};
	printf("reversePair number is:%d\n",reverserPairNumber(array, sizeof(array)/sizeof(int)) );
	return 0;
}