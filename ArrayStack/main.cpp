#include "ArrayStack.h"

int main(){
	int i = 0;
	ArrayStack* Stack = NULL;
	
	AS_CreateStack(&Stack, 10);
	
	AS_Push(Stack, 3);
	AS_Push(Stack, 35);
	AS_Push(Stack, 43);
	AS_Push(Stack, 75);
	
	printf("Capacity: %d, Size: %d, Top: %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
	
	AS_DestroyStack(Stack);
	
	return 0;
}
