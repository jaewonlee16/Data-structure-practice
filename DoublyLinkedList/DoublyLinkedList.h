#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct _Node{
	ElementType Data;
	struct _Node* PreviousNode;
	struct _Node* NextNode;
}Node;


Node* DLL_CreateNode(ElementType NewData);
void DLL_DestroyNode(Node* Node);
void AppendNode(Node** Head, Node* NewNode);
void DLL_InsertAfter(Node* Current, Node* NewNode);
void DLL_RemoveNode(Node** Head, Node* Remove);
Node* DLL_GetNodeAt(Node* Head, int Location);
int DLL_GetNodeCount(Node* Head);

#endif
