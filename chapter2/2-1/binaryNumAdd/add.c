#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct binaryNumber
{
	int * bitList;
	int length;
};	
typedef struct binaryNumber * BinaryNumber;

//通过字符串来创建一个可以想家的数
BinaryNumber createBinaryNumber(char * str)
{
	int i=0;
	BinaryNumber newNumber = (BinaryNumber)malloc(sizeof(struct binaryNumber));
	if(newNumber==NULL)
		return NULL;
	newNumber->bitList=(int *)malloc(sizeof(int)*strlen(str));
	for (i = 0; i < strlen(str); ++i)
	{
		if(str[i]=='0')
			newNumber->bitList[i]=0;
		else if(str[i]=='1')
			newNumber->bitList[i]=1;
		else
		{
			free(newNumber->bitList);
			free(newNumber);
			fprintf(stderr, "%s%s\n", "错误:二进制数字，只可以时'0'和'1' ",str);
			return NULL;
		}
	}
	newNumber->length = strlen(str);
	return newNumber;
}

//用来删除一个二进制的数据
void deleteBinaryNumber(BinaryNumber deleteNumber)
{
	free(deleteNumber->bitList);
	free(deleteNumber);
	return;
}


BinaryNumber binaryNumberAdd(const BinaryNumber number1,const BinaryNumber number2 )
{
	int carryFlag=0;
	int * tempPtr;
	int i=0;
	if(number1 == NULL || number2 ==NULL)
	{
		perror("binaryNumberAdd:参数不能为空");
		return NULL;
	}
	BinaryNumber resultBinaryNumber = (BinaryNumber)malloc(sizeof(struct binaryNumber));
	//最长的那个来决定新生成的数的长度+1
	resultBinaryNumber->length=(number1->length > number2->length?number1->length:number2->length)+1;
	resultBinaryNumber->bitList=(int *)malloc(sizeof(int)*(resultBinaryNumber->length+1));
	for(i=0;i<resultBinaryNumber->length-1;++i)
	{
		int temp=(i<number1->length?number1->bitList[i]:0)+\
				 (i<number2->length?number2->bitList[i]:0);//决定两个长度不相同的数相加！
		fprintf(stderr, "%d+++\n",temp );
		if(temp==0)
		{
			resultBinaryNumber->bitList[i]=carryFlag;
			carryFlag=0;
		}
		else if(temp==1)
		{
			if(carryFlag==1)
			{
				resultBinaryNumber->bitList[i]=0;
				carryFlag=1;
			}
			else
				resultBinaryNumber->bitList[i]=1;
		}
		else if(temp==2)
		{
			resultBinaryNumber->bitList[i]=carryFlag;
			carryFlag=1;
		}
	}
	if(carryFlag ==1)
		resultBinaryNumber->bitList[i]=1;
	else
		resultBinaryNumber->length=i-1;
	return resultBinaryNumber;
}

char * binaryNumberToString(BinaryNumber number)
{
	int i=0;
	char * str = (char *)malloc(sizeof(char)*number->length);
	for (i = number->length-1; i >=0; --i)
	{
		if(number->bitList[number->length-i-1]==0)
			str[i]='0';
		else
			str[i]='1';
	}
	return str;
}

int main(int argc, char const *argv[])
{
	BinaryNumber number1=createBinaryNumber("11111111");
	BinaryNumber number2=createBinaryNumber("10000001");
	BinaryNumber result=binaryNumberAdd(number1, number2);
	char * resultStr = binaryNumberToString(result);
	printf("11111111 + 00000001 ->>The result is :%s\n",resultStr);
	deleteBinaryNumber(number1);
	deleteBinaryNumber(number2);
	deleteBinaryNumber(result);
	free(resultStr);
	return 0;
}