#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode(ElementType NewData){
	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
	NewNode->data = NewData;
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;
	
	return NewNode;
}

void LCRS_DestroyNode(LCRSNode* Node){
	free(Node);
}

void LCRS_DestroyTree(LCRSNode* Root){
	if (Root->RightSibling != NULL)
		LCRS_DestroyNode(Root->RightSibling);
	if (Root->LeftChild != NULL)
		LCRS_DestroyNode(Root->LeftChild);
	
	Root->LeftChild = NULL;
	Root->RightSibling = NULL;
	
	LCRS_DestroyNode(Root);
}


void LCRS_AddChildNode(LCRSNode* ParentNode, LCRSNode* ChildNode){
	if (ParentNode->LeftChild == NULL){
		ParentNode->LeftChild = ChildNode;
	}
	else{
		LCRSNode* tempNode = ParentNode->LeftChild;
		while (tempNode->RightSibling != NULL)	{
			tempNode = tempNode->RightSibling;
		}
		tempNode->RightSibling = ChildNode;
	}
}

void LCRS_PrintTree(LCRSNode* Node, int Depth){
	for (int i = 0; i < Depth; i++){
		printf("   ");
	}
	printf("%c\n", Node->data);
	
	if (Node->LeftChild != NULL)
		LCRS_PrintTree(Node->LeftChild, Depth + 1);
	if (Node->RightSibling != NULL)
		LCRS_PrintTree(Node->RightSibling, Depth);
}
