#include "PriorityQueue.h"

PriorityQueue* PQ_Create (int InitialSize){
	PriorityQueue* NewQueue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	NewQueue->Nodes = (PQNode*)malloc(sizeof(PQNode) * InitialSize);
	NewQueue->Capacity = InitialSize;
	NewQueue->UsedSize = 0;
	
	return NewQueue;
}

void PQ_Destroy(PriorityQueue* PQ){
	free(PQ->Nodes);
	free(PQ);
}

void PQ_Enqueue(PriorityQueue* PQ, PQNode NewData){
	if (PQ->UsedSize == PQ->Capacity){
		PQ->Capacity = 2 * PQ->Capacity + 1;
		
		PQ->Nodes = (PQNode*)realloc(PQ->Nodes, 
										sizeof(PQNode) * PQ->Capacity);
	}
	
	PQ->Nodes[PQ->UsedSize] = NewData;
	
	int currentPosition = PQ->UsedSize;
	int parentPosition = PQ_GetParent(currentPosition);
	
	
	while (currentPosition > 0
			&& PQ->Nodes[currentPosition].Priority < PQ->Nodes[parentPosition].Priority){
		PQ_SwapNodes(PQ, currentPosition, parentPosition)		;
		
		currentPosition = parentPosition;
		parentPosition = PQ_GetParent(currentPosition);
	}
	
	PQ->UsedSize++;
}

void PQ_Dequeue(PriorityQueue* PQ, PQNode* Root){
	memcpy(Root, &PQ->Nodes[0], sizeof(PQNode));
	memset(&PQ->Nodes[0], 0, sizeof(PQNode));
	
	PQ->UsedSize--;
	
	PQ_SwapNodes(PQ, 0, PQ->UsedSize);
	
	int parentPosition = 0;
	int leftChild = PQ_GetLeftChild(parentPosition);
	int rightChild = leftChild + 1;
	
	while(1){
		int selectedChild = 0;
		
		if (leftChild >= PQ->UsedSize)
			break;
		if (rightChild >= PQ->UsedSize)
			selectedChild = leftChild;
		else{
			bool isLeftChildPriority 
						= PQ->Nodes[leftChild].Priority < PQ->Nodes[rightChild].Priority;
			
			if (isLeftChildPriority)
				selectedChild = leftChild;
			else
				selectedChild = rightChild;
		}
		
		bool isSelectedChildPriority 
					= PQ->Nodes[selectedChild].Priority < PQ->Nodes[parentPosition].Priority;
		
		if (isSelectedChildPriority){
			PQ_SwapNodes(PQ, selectedChild, parentPosition);
			
			parentPosition = selectedChild;
			leftChild = PQ_GetLeftChild(parentPosition);
			rightChild = leftChild + 1;
		}
		else
			break;
		
		if (PQ->UsedSize < (PQ->Capacity) / 2){
			PQ->Capacity /= 2;
			PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
		}
	}
}

int PQ_GetParent(int Index){
	return (int) ((Index-1) / 2);
}

int PQ_GetLeftChild(int Index){
	return Index * 2 + 1;
}

void PQ_SwapNodes(PriorityQueue* PQ, int Index1, int Index2){
	PQNode* temp = (PQNode*)malloc(sizeof(PQNode));
	
	memcpy(temp, &PQ->Nodes[Index1], sizeof(PQNode));
	memcpy(&PQ->Nodes[Index1], &PQ->Nodes[Index2], sizeof(PQNode));
	memcpy(&PQ->Nodes[Index2], temp, sizeof(PQNode));
	
	free(temp);
}

int PQ_IsEmpty(PriorityQueue* PQ){
	return PQ->UsedSize == 0;
}
