#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct _SBTNode{
	struct _SBTNode* Left;
	struct _SBTNode* Right;
	
	ElementType Data;
}SBTNode;

SBTNode* SBT_CreateNode(ElementType NewData);
void SBT_DestroyNode(SBTNode* node);
void SBT_DestroyTree(SBTNode* Root);

void SBT_PreOrderPrintTree(SBTNode* node);
void SBT_InOrderPrintTree(SBTNode* node);
void SBT_PostOrderPrintTree(SBTNode* node);

#endif
