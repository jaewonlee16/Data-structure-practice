#include "OpenAddressing.h"

HashTable* OAHT_CreateHashTable (int TableSize){
	HashTable* NewTable = (HashTable*)malloc(sizeof(HashTable));
	
	NewTable->Table = (ElementType*)malloc(sizeof(ElementType) * TableSize);
	memset(NewTable->Table, 0, sizeof(ElementType) * TableSize);
	
	NewTable->OccupiedCount = 0;
	NewTable->TableSize = TableSize;
	
	return NewTable;
}

void OAHT_DestroyHashTable (HashTable* HT){
	for (int i = 0; i < HT->TableSize; i++){
		OAHT_ClearElement(&HT->Table[i]);
	}
	
	free(HT->Table);
	free(HT);
}

void OAHT_ClearElement (ElementType* Element){
	if (Element->Status == EMPTY)
		return;
	
	free(Element->Key);
	free(Element->Value);
}


void OAHT_Set(HashTable** HT, KeyType Key, ValueType Value){
	int Address = OAHT_Hash(Key, strlen(Key), (*HT)->TableSize);
	int StepSize = OAHT_Hash(Key, strlen(Key), (*HT)->TableSize);
	
	double Usage = (double) (*HT)->OccupiedCount / (*HT)->TableSize;
	if (Usage > 0.5)
		OAHT_Rehash(HT);
	
	while ((*HT)->Table[Address].Status != EMPTY
			&& strcmp(Key, (*HT)->Table[Address].Key) != 0){
		
		printf("Collision  Key: %s, Addreess: %d, StepSize:%d\n", Key, Address, StepSize);
		
		Address = (Address + StepSize) % (*HT)->TableSize;
	}
	
	(*HT)->Table[Address].Key = (char*)malloc(sizeof(char) * (strlen(Key) + 1));
	strcpy((*HT)->Table[Address].Key, Key);
	
	(*HT)->Table[Address].Value = (char*)malloc(sizeof(char) * (strlen(Value) + 1));
	strcpy((*HT)->Table[Address].Value, Value);
	
	(*HT)->Table[Address].Status = OCCUPIED;
	
	(*HT)->OccupiedCount++;
	
	printf("Key: %s entered at address: %d\n", Key, Address);
}

ValueType OAHT_Get (HashTable* HT, KeyType Key){
	int Address = OAHT_Hash(Key, strlen(Key), HT->TableSize);
	int StepSize = OAHT_Hash2(Key, strlen(Key), HT->TableSize);
	
	while (HT->Table[Address].Status != EMPTY
			&& strcmp(HT->Table[Address].Key, Key) != 0){
		Address = (Address + StepSize) % HT->TableSize;
	}
	
	return HT->Table[Address].Value;
}

int OAHT_Hash(KeyType Key, int KeyLength, int TableSize){
	int HashValue = 0;
	
	for (int i = 0; i < KeyLength; i++){
		HashValue = (HashValue << 3) + Key[i];
	}
	
	HashValue = HashValue % TableSize;
	
	return HashValue;
}

int OAHT_Hash2(KeyType Key, int KeyLength, int TableSize){
	int HashValue = 0;
	
	for (int i = 0; i < KeyLength; i++){
		HashValue = (HashValue << 2) + Key[i];
	}
	
	HashValue = HashValue % (TableSize - 3);
	
	return HashValue + 1;
}


void OAHT_Rehash (HashTable** HT){
	ElementType* OldTable = (*HT)->Table;
	
	HashTable* NewTable = OAHT_CreateHashTable((*HT)->TableSize * 2);
	
	printf("\n rehashed, New Table size is : %d", NewTable->TableSize);
	
	for (int i = 0; i < (*HT)->TableSize; i++){
		if (OldTable[i].Status == OCCUPIED)
			OAHT_Set(&NewTable, OldTable[i].Key, OldTable[i].Value);
	}
	
	OAHT_DestroyHashTable((*HT));;
	
	(*HT) = NewTable;
}
