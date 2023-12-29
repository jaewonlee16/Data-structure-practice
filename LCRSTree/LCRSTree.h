#ifndef LCRSTREE_H
#define LCRSTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct _LCRSNode{
	ElementType data;
	
	struct _LCRSNode* LeftChild;
	struct _LCRSNode* RightSibling;
}LCRSNode;


LCRSNode* LCRS_CreateNode(ElementType NewData);
void LCRS_DestroyNode(LCRSNode* Node);
void LCRS_DestroyTree(LCRSNode* Root);

void LCRS_AddChildNode(LCRSNode* ParentNode, LCRSNode* ChildNode);
void LCRS_PrintTree(LCRSNode* Node, int Depth);

#endif
