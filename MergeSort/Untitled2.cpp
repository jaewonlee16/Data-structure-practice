#include <stdio.h>
#include <stdlib.h>

void MergeSort(int* DataSet, int StartIndex, int EndIndex);
void Merge(int* DataSet, const int StartIndex, const int MiddleIndex, const int EndIndex);
void PrintArray(int* array, int size);

int main(){
	int dataSet[] = {334, 6, 4, 2, 3, 1, 5, 117, 12, 34};
	int Length = sizeof dataSet / sizeof dataSet[0];
	
	MergeSort (dataSet, 0, Length - 1);
	
	PrintArray(dataSet, Length);
	
	return 0;
}

void MergeSort(int* DataSet, int StartIndex, int EndIndex){
	if (EndIndex - StartIndex < 1)
		return;
	
	int middleIndex = (int)((StartIndex + EndIndex) / 2);
	
	MergeSort(DataSet, StartIndex, middleIndex);
	MergeSort(DataSet, middleIndex + 1, EndIndex);
	
	Merge(DataSet, StartIndex, middleIndex, EndIndex);
}

void Merge(int* DataSet, const int StartIndex, const int MiddleIndex, const int EndIndex){
	int LeftIndex = StartIndex;
	int RightIndex = MiddleIndex + 1;
	int destIndex = 0;
	
	int* Destination = (int*)malloc(sizeof(int) * (EndIndex - StartIndex + 1));
	
	while (LeftIndex <= MiddleIndex && RightIndex <= EndIndex){
		if (DataSet[LeftIndex] < DataSet[RightIndex]){
			Destination[destIndex] = DataSet[LeftIndex];
			LeftIndex++;
		}
		else{
			Destination[destIndex] = DataSet[RightIndex];
			RightIndex++;
		}
		
		destIndex++;
	}
	
	while (LeftIndex <= MiddleIndex){
		Destination[destIndex++] = DataSet[LeftIndex++];
	}
	
	while (RightIndex <= EndIndex){
		Destination[destIndex++] = DataSet[RightIndex++];
	}
	
	destIndex = 0;
	for (int i = StartIndex; i <= EndIndex; i++){
		DataSet[i] = Destination[destIndex++];
	}
	
	free (Destination);
}

void PrintArray(int* array, int size){
	for (int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}
