#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** p_Stack, int Capacity){
	*p_Stack = (ArrayStack*)malloc(sizeof(ArrayStack));
	
	(*p_Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);
	
	(*p_Stack)->Capacity = Capacity;
	(*p_Stack)->Top = 0;
}

void AS_DestroyStack(ArrayStack* Stack){
	free(Stack->Nodes);
	free(Stack);
}

void AS_Push(ArrayStack* Stack, ElementType Data){
	int position = Stack->Top;
	
	Stack->Nodes[position].Data = Data;
	Stack->Top++;
}

ElementType AS_Pop(ArrayStack* Stack){
	int position = --(Stack->Top);
	return Stack->Nodes[position].Data;
}

ElementType AS_Top(ArrayStack* Stack){
	return Stack->Nodes[Stack->Top - 1].Data;
}

int AS_GetSize(ArrayStack* Stack){
	return Stack->Top; 
}

int AS_IsEmpty(ArrayStack* Stack){
	return (Stack->Top == 0);
}
