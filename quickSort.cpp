#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "quick_sort.h"

#define _ARRAY_LEN_ 100
void quick_sort(int* array, int low, int high)
{
	int Low = low, High = high;
	int* Array = array;

	if(Low < High)
		{
			int pivot = Array[Low];
			int median = Low;

			while(Low < High)
			{
				while(Low < High && Array[High] > pivot)
					High --;
				if(Low < High) Array[Low] = Array[High];
				while(Low < High && Array[Low] <= pivot)
					Low ++;
				if(Low < High) Array[High] = Array[Low];
				
				median = Low;
				Array[median] = pivot;
			}

			quick_sort(Array, low, median-1);
			quick_sort(Array, median+1, high);
		}
}

void swap(int* array, int left, int right)
{
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}

void _swap(void* left, void* right, int size)
{
	char buffer[size];
	memcpy(buffer, left, size);
	memcpy(left, right, size);
	memcpy(right, buffer, size);
}

int print_array(int *array, int start, int end)
{
	int _start = start, _end = end;
	while(_start <=  _end)
	{
		printf("%d,",array[_start]);
		_start ++;
	}
	printf("\n");
	return end - start + 1;
}

int _random(int* array, int len)
{
	int i = 0;
	srand((unsigned)time(NULL));
	while(i++ < len)
		array[i] = rand()%100;
	return len;
}

int main(int argc, char* argv[])
{
	int array[_ARRAY_LEN_];
	_random(array, _ARRAY_LEN_);
	quick_sort(array, 0, _ARRAY_LEN_ -1);
	print_array(array, 0, _ARRAY_LEN_ -1);
	return 0;		
}
