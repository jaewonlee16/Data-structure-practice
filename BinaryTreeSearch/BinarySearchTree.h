#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct _BSTNode{
	struct _BSTNode* Left;
	struct _BSTNode* Right;
	
	ElementType Data;
}BSTNode;

BSTNode* BST_CreateNode (ElementType NewData);
void BST_DestroyNode (BSTNode* Remove);
void BST_DestroyTree (BSTNode* Tree);

BSTNode* BST_SearchNode (BSTNode* Tree, ElementType Target);
BSTNode* BST_SearchMinNode (BSTNode* Tree);
void BST_InsertNode (BSTNode* Tree, BSTNode* Child);
BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target);
void BST_InorderPrint (BSTNode* Tree);

#endif
