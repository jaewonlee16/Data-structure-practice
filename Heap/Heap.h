#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int ElementType;

typedef struct _HeapNode{
	ElementType Data;
}HeapNode;

typedef struct _Heap{
	HeapNode* Nodes;
	int Capacity;
	int UsedSize;
}Heap;

Heap* HEAP_Create(int InitialSize);
void HEAP_Destroy(Heap* H);
void HEAP_Insert(Heap* H, ElementType NewData);
void HEAP_DeleteMin(Heap* H, HeapNode* Root);
int HEAP_GetParent(int Index);
int HEAP_GetLeftChild(int Index);
void HEAP_SwapNodes(Heap* H, int index1, int index2);
void HEAP_PrintNodes(Heap* H);


#endif
