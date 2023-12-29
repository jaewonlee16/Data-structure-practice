#include "BinaryTree.h"

SBTNode* SBT_CreateNode(ElementType NewData){
	SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));
	
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;
}

void SBT_DestroyNode(SBTNode* node){
	free(node);
}

void SBT_DestroyTree(SBTNode* Root){
	if (Root == NULL)
		return;
	
	SBT_DestroyTree(Root->Right);
	SBT_DestroyTree(Root->Left);
	
	free(Root);
}


void SBT_PreOrderPrintTree(SBTNode* node){
	if (node == NULL)
		return;
	
	printf(" %c", node->Data);
	
	SBT_PreOrderPrintTree(node->Left);
	SBT_PreOrderPrintTree(node->Right);
}

void SBT_InOrderPrintTree(SBTNode* node){
	if (node == NULL)
		return;
	
	SBT_InOrderPrintTree(node->Left);
	
	printf(" %c", node->Data);
	
	SBT_InOrderPrintTree(node->Right);
}

void SBT_PostOrderPrintTree(SBTNode* node){
	if (node == NULL)
		return;
	
	SBT_PostOrderPrintTree(node->Left);
	SBT_PostOrderPrintTree(node->Right);
	
	printf(" %c", node->Data);
}

