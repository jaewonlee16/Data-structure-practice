#include <stdio.h>

void swap (int* a, int* b);
int Partition(int* array, int left, int right);
void QuickSort(int* array, int left, int right);
void printArray(int* array, int length);

int main(){
	int dataSet[] = {6, 4, 2, 3, 1, 5}	;
	int length = sizeof dataSet / sizeof dataSet[0];
	
	QuickSort(dataSet, 0, length - 1);
	
	printArray(dataSet, length);
	return 0;
}

void swap (int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int* array, int left, int right){
	int pivot = array[left];
	int first = left;
	left++;
	
	while (left <= right){
		while (array[left] <= pivot && left < right){
			++left;
		}
		while (array[right] >= pivot && left <= right){
			--right;
		}
		
		if (left < right)
			swap(array + left, array + right);
		else
			break;
	}
	
	swap(&array[first], &array[right]);
	return right;
}

void QuickSort(int* array, int left, int right){
	if (left < right){
		int index = Partition(array, left, right);
		
		QuickSort(array, left, index - 1);
		QuickSort(array, index + 1, right);
	}
}

void printArray(int* array, int length){
	for (int i = 0; i < length; i++){
		printf("%d ", *array++);
	}
}
