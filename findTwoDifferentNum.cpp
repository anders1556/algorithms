/*
 * main.cpp
 *
 *  Created on: 2014年9月18日
 *      Author: Administrator
 */

//一个数组中有2个数只出现依次,其他数出现两次

#include <iostream>
#include <stddef.h>

size_t findFirstBitIs1(int number)
{
	int indexBit = -1;
	while(number!=0 && indexBit<32)
	{
		number = number >> 1;
		++indexBit;
	}
	return indexBit;
}

size_t findLastBitIs1(int number)
{
	return number & ~(number-1);
}

bool isBit1(int num, size_t indexBit)
{
	num = num >> indexBit;
	return (num&1);
}

void findNumAppearOnce(int array[], int length, int& num1, int& num2)
{
	if(length < 2)
		return ;
	int resultExclusiveOR = 0;
	for(int i=0; i<length; i++)
	{
		resultExclusiveOR ^= array[i];
	}

	size_t indexOf1 = findFirstBitIs1(resultExclusiveOR);
	num1 = num2 = 0;
	for(int j=0; j<length; j++)
	{
		if(isBit1(array[j],indexOf1))
			num1 ^= array[j];
		else
			num2 ^= array[j];
	}
}
int main()
{
	int array[] = {1,1,2,2,3,3,4,5,6,6,7,7,8,8};
	int num1,num2;
	findNumAppearOnce(array,14,num1,num2);
	std::cout << num1 <<" " << num2 << std::endl;
}
