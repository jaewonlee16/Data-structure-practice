#include "BinarySearchTree.h"

BSTNode* BST_CreateNode (ElementType NewData){
	BSTNode* NewNode = (BSTNode*)malloc(sizeof(BSTNode));
	
	NewNode->Data = NewData;
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	
	return NewNode;
}

void BST_DestroyNode (BSTNode* Remove){
	free(Remove);
}

void BST_DestroyTree (BSTNode* Tree){
	if (Tree->Right != NULL)
		BST_DestroyTree(Tree->Right);
	if (Tree->Left != NULL)
		BST_DestroyTree(Tree->Left);
	
	Tree->Left = NULL;
	Tree->Right = NULL;
	free(Tree);
}


BSTNode* BST_SearchNode (BSTNode* Tree, ElementType Target){
	if (Tree == NULL)
		return NULL;
	if (Tree->Data == Target)
		return Tree;
	else if (Tree->Data > Target)
		return BST_SearchNode (Tree->Right, Target);
	else
		return BST_SearchNode (Tree->Left, Target);
}

BSTNode* BST_SearchMinNode (BSTNode* Tree){
	BSTNode* MinNode = Tree;
	
	while (MinNode->Left != NULL){
		MinNode = MinNode->Left;
	}
	
	return MinNode;
}

void BST_InsertNode (BSTNode* Tree, BSTNode* Child){
	if (Tree->Data > Child->Data){
		if (Tree->Left == NULL)
			Tree->Left = Child;
		else
			BST_InsertNode (Tree->Left, Child);
	}
	else if (Tree->Data < Child->Data){
		if (Tree->Right == NULL)
			Tree->Right = Child;
		else
			BST_InsertNode (Tree->Right, Child);
	}
}

BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target){
	BSTNode* Removed = NULL;
	
	if (Tree == NULL)
		return NULL;
	
	if (Tree->Data > Target){
		Removed = BST_RemoveNode(Tree->Left, Tree, Target);
	}
	else if (Tree->Data < Target)
		Removed = BST_RemoveNode(Tree->Right, Tree, Target);
	else{
		// if (Tree->Data == Target)
		
		Removed = Tree;
		
		bool isNoChild = Tree->Left == NULL && Tree->Right == NULL;
		bool isBothChildren = Tree->Left != NULL && Tree->Right != NULL;
		
		if (isNoChild){
			if (Parent->Left == Tree)
				Parent->Left = NULL;
			else if (Parent->Right == Tree)
				Parent->Right = NULL;	
		}
		else if (isBothChildren){
			BSTNode* minNode = BST_SearchMinNode(Tree->Right);
			minNode = BST_RemoveNode(Tree, NULL, minNode->Data);
			
			Tree->Data = minNode->Data;
		}
		else{
			BSTNode* temp = NULL;
			
			if (Tree->Left == NULL)
				temp = Tree->Right;
			else
				temp = Tree->Left;
			
			if (Parent->Right == Tree)
				Parent->Right = temp;
			else
				Parent->Left = temp;
			
		}
	}
	
	return Removed;
}

void BST_InorderPrint (BSTNode* Tree){
	if (Tree->Left != NULL)
		BST_InorderPrint (Tree->Left);
		
	printf("%d ", Tree->Data);
	
	if (Tree->Right != NULL)
		BST_InorderPrint (Tree->Right);
}
