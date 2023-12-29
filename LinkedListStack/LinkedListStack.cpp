#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** p_Stack){
	*p_Stack = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*p_Stack)->List = NULL;
	(*p_Stack)->Top = NULL;
}

void LLS_DestroyStack(LinkedListStack* Stack){
	while (!LLS_IsEmpty(Stack)){
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyNode(Popped);
	}
	
	free(Stack);
}


Node* LLS_CreateNode(char* NewData){
	Node* NewNode = (Node*)malloc(sizeof(Node*));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);
	
	strcpy(NewNode->Data, NewData);
	
	NewNode->NextNode = NULL;
	
	return NewNode;
}

void LLS_DestroyNode(Node* node){
	free(node->Data);
	free(node);
}


void LLS_Push(LinkedListStack* Stack, Node* NewNode){
	if (Stack->List == NULL){
		Stack->List = NewNode;
	}
	else{
		Stack->Top->NextNode = NewNode;
	}
	
	Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack){
	Node* Popped = Stack->Top;
	
	if (Stack->List == Stack->Top){
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else{
		Node* Current = Stack->List;
		while (Current != NULL && Current->NextNode != Stack->Top){
			Current = Current->NextNode;
		}
		Stack->Top = Current;
		Current->NextNode = NULL;
	}
	
	return Popped;
}


Node* LLS_Top(LinkedListStack* Stack){
	return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack){
	int count = 0;
	Node* Current = Stack->List;
	
	while (Current!= NULL){
		Current = Current->NextNode;
		count++;
	}
	
	return count;
	
}

int LLS_IsEmpty(LinkedListStack* Stack){
	return Stack->List == NULL;
}

