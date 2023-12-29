#include "LinkedListStack.h"

int main(){
	int i = 0;
	int Count = 0;
	Node* Popped;
	
	LinkedListStack* Stack;
	
	LLS_CreateStack(&Stack);
	
	LLS_Push(Stack, LLS_CreateNode("abc"));
	LLS_Push(Stack, LLS_CreateNode("def"));
	LLS_Push(Stack, LLS_CreateNode("efg"));
	LLS_Push(Stack, LLS_CreateNode("hij"));
	
	Popped = LLS_Pop(Stack);
	Popped = LLS_Pop(Stack);
	printf("%s\n\n", Popped->Data);
	
	Count = LLS_GetSize(Stack);
	printf("Size: %d, Top: %s\n\n", Count, LLS_Top(Stack)->Data);
	
	LLS_DestroyStack(Stack);
	return 0;
}
