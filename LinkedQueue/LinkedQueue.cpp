#include "LinkedQueue.h"

void LQ_CreateQueue(LinkedQueue** Queue){
	*Queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}

void LQ_DestroyQueue(LinkedQueue* Queue){
	while (!LQ_IsEmpty(Queue)){
		Node* Popped = LQ_Dequeue(Queue);
		LQ_DestroyNode(Popped);
	}
	
	free(Queue);
}


Node* LQ_CreateNode(Vertex* NewData){
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = NewData;
	
	NewNode->NextNode = NULL;
	
	return NewNode;
}

void LQ_DestroyNode(Node* node){
	free(node);
}


void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode){
	if (Queue->Front == NULL){
		Queue->Front = NewNode;
	}
	else{
		Queue->Rear->NextNode = NewNode;
	}
	
	Queue->Count++;
	Queue->Rear = NewNode;
}

Node* LQ_Dequeue(LinkedQueue* Queue){
	Node* front = Queue->Front;
	if (Queue->Front == Queue->Rear){
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else{
		Queue->Front = front->NextNode;
	}
	
	Queue->Count--;
	
	return front;
}

int LQ_IsEmpty(LinkedQueue* Queue){
	return Queue->Count == 0;
}

