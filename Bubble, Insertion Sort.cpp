#include <stdio.h>
#include <string.h>

void BubbleSort(int* array, int length);
void swap(int* a, int* b);
void InsertionSort(int* array, int length);
void printArray(int* array, int length);

int main(){
	int DataSet[] = {6, 4, 2, 3, 1, 5};
	int Length = sizeof DataSet / sizeof DataSet[0];
	
	BubbleSort(DataSet, Length);
	InsertionSort(DataSet, Length);
	
	printArray(DataSet, Length);
	return 0;
}

void BubbleSort(int* array, int length){
	for (int i = 0; i < length - 1; i++){
		for (int j = 0; j < length - i - 1; j++){
			if (*(array + j) > *(array + j + 1))
				swap(array + j, array + j + 1);
		}
	}
}

void swap(int* a, int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void InsertionSort(int* array, int length){
	int value = 0;
	
	for (int i = 1; i < length; i++){
		if (*(array + i - 1) <= *(array + i))
			continue;
		
		value = *(array + i) ;
		
		for (int j = 0; j < i; j++){
			if (*(array + j) > value){
				memmove(array + j + 1, array + j, sizeof(array[0]) * (i - j));
				*(array + j) = value;
				break;
			}
		}
	}
}

void printArray(int* array, int length){
	for (int i = 0; i < length; i++){
		printf("%d ", *array++);
	}
}


