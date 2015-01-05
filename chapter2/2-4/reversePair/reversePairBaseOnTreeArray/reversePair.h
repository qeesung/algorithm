#ifndef _REVERSEPAIR_H
#define _REVERSEPAIR_H

#include "treeArray.h"

struct disrect_s
{
	int value;
	int index;
};


void MERGE(struct disrect_s subArray[] , const int left , const int right);
void mergeSort(struct disrect_s inputArray[] , const int arrayLength);
//计算逆序对的数量
int reverserPairNumber(const int inputArray[] , const int arrayLength);


#endif