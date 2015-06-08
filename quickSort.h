#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_
void quick_sort(int* array, int low, int high);
void swap(int* array, int left, int right);
void _swap(void* left, void* right, int size);
int print_array(int* array, int start, int end);
int _random(int* array, int len);
#endif
