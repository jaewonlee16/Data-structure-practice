#include "Heap.h"

Heap* HEAP_Create(int InitialSize){
	Heap* NewHeap = (Heap*)malloc(sizeof(Heap));
	NewHeap->Capacity = InitialSize;
	NewHeap->UsedSize = 0;
	NewHeap->Nodes = (HeapNode*)malloc(sizeof(HeapNode) * NewHeap->Capacity);
}

void HEAP_Destroy(Heap* H){
	free (H->Nodes);
	
	free (H);
}

void HEAP_Insert(Heap* H, ElementType NewData){
	int currentPosition = H->UsedSize;
	int parentPosition = HEAP_GetParent(currentPosition);
	
	if (currentPosition == H->Capacity){
		H->Capacity *= 2;
		H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
	}
	
	H->Nodes[currentPosition].Data = NewData;
	
	while (currentPosition > 0 
		&& H->Nodes[currentPosition].Data < H->Nodes[parentPosition].Data){
			HEAP_SwapNodes(H, currentPosition, parentPosition);
			
			currentPosition = parentPosition;
			parentPosition = HEAP_GetParent(currentPosition);
		}
	
	H->UsedSize++;
}

void HEAP_DeleteMin(Heap* H, HeapNode* Root){
	int parentPosition = 0;
	int leftPosition = 0;
	int rightPosition = 0;
	
	memcpy(Root, &H->Nodes[0], sizeof(HeapNode));
	memset(&H->Nodes[0], 0, sizeof(HeapNode));
	H->UsedSize--;
	HEAP_SwapNodes(H, 0, H->UsedSize);
	
	leftPosition = HEAP_GetLeftChild(0);
	rightPosition = leftPosition + 1;
	
	while(1){
		int selectedChild = 0;
		
		if (leftPosition >= H->UsedSize)
			break;
		if (rightPosition >= H->UsedSize)
			selectedChild = leftPosition;
		else{
			if (H->Nodes[leftPosition].Data < H->Nodes[rightPosition].Data)
				selectedChild = leftPosition;
			else
				selectedChild = rightPosition;
		}
		
		if (H->Nodes[selectedChild].Data < H->Nodes[parentPosition].Data){
				HEAP_SwapNodes(H, selectedChild, parentPosition);
				parentPosition = selectedChild;
				leftPosition = HEAP_GetLeftChild(parentPosition);
				rightPosition = leftPosition + 1;
			}
			else
				break;
	}
	
	if (H->UsedSize < (H->Capacity / 2)){
		H->Capacity /= 2;
		H->Nodes
			= (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
	}
}

int HEAP_GetParent(int Index){
	return (int)((Index - 1) / 2);
}

int HEAP_GetLeftChild(int Index){
	return Index * 2 + 1;
}

void HEAP_SwapNodes(Heap* H, int index1, int index2){
	HeapNode* temp = (HeapNode*)malloc(sizeof(HeapNode));
	
	memcpy(temp, &H->Nodes[index1], sizeof(HeapNode));
	memcpy(&H->Nodes[index1], &H->Nodes[index2], sizeof(HeapNode));
	memcpy(&H->Nodes[index2], temp, sizeof(HeapNode));
}

void HEAP_PrintNodes(Heap* H){
	for (int i = 0; i < H->UsedSize; i++){
		printf("%d ", H->Nodes[i].Data);
	}
	printf("\n");
}
