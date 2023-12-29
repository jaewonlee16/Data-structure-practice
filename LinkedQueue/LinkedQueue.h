#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Graph.h"

typedef struct _Node{
	Vertex* Data;
	struct _Node* NextNode;
}Node;

typedef struct _LinkedQueue{
	Node* Front;
	Node* Rear;
	int Count;	
}LinkedQueue;

void LQ_CreateQueue(LinkedQueue** Queue);
void LQ_DestroyQueue(LinkedQueue* Queue);

Node* LQ_CreateNode(Vertex* NewData);
void LQ_DestroyNode(Node* node);

void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode);
Node* LQ_Dequeue(LinkedQueue* Queue);

int LQ_IsEmpty(LinkedQueue* Queue);

#endif
