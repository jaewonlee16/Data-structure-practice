#include "Chaining.h"

HashTable* CHT_CreateHashTable (int TableSize){
	HashTable* NewTable = (HashTable*)malloc(sizeof(HashTable));
	
	NewTable->Table = (Node**)malloc(sizeof(Node) * TableSize);
	NewTable->TableSize = TableSize;
	
	return NewTable;
}

void CHT_DestroyHashTable (HashTable* HT){
	
}


Node* CHT_CreateNode (KeyType Key, ValueType Value){
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	NewNode->Key = (char*)malloc(sizeof(char) * (strlen(Key) + 1));
	strcpy(NewNode->Key, Key);
	
	NewNode->Value = (char*)malloc(sizeof(char) * (strlen(Value) + 1));
	strcpy(NewNode->Value, Value);
	
	NewNode->Next = NULL;
	
	return NewNode;
}

void CHT_DestroyNode(Node* TheNode){
	free(TheNode->Key);
	free(TheNode->Value);
	free(TheNode);
}


void CHT_Set (HashTable* HT, KeyType Key, ValueType Value){
	int Address = CHT_Hash(Key, strlen(Key), HT->TableSize);
	
	Node* NewNode = CHT_CreateNode(Key, Value);
	
	if (HT->Table[Address] == NULL)
		HT->Table[Address] = NewNode;
	else{
		Node* L = HT->Table[Address];
		NewNode->Next = L;
		HT->Table[Address] = NewNode;
		
		printf("collision    %s,    %d\n", Key, Address);
	}
}

ValueType CHT_Get (HashTable* HT, KeyType Key){
	int Address = CHT_Hash(Key, strlen(Key), HT->TableSize);
	
	Node* target = HT->Table[Address];
	
	while (1){
		if (target == NULL)	
			return NULL;
		else if (strcmp(target->Key, Key) == 0)
			return target->Value;
		else
			target = target->Next;
	}
}

int CHT_Hash (KeyType Key, int KeyLength, int TableSize){
	int i = 0;
	int HashValue = 0;
	
	for (i = 0; i < KeyLength; i++){
		HashValue = (HashValue << 3) + Key[i];
	}
	
	HashValue = HashValue % TableSize;
	
	return HashValue;
}
