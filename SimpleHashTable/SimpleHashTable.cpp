#include "SimpleHashTable.h"

HashTable* SHT_CreateHashTable(int TableSize){
	HashTable* NewHash = (HashTable*)malloc(sizeof(HashTable));
	NewHash->TableSize = TableSize;
	NewHash->Table = (Node*)malloc(sizeof(Node) * TableSize);
	
	return NewHash;
}

void SHT_Set(HashTable* HT, KeyType Key, ValueType Value){
	int address = SHT_Hash(Key, HT->TableSize);
	
	HT->Table[address].Key = Key;
	HT->Table[address].Value = Value;
}

ValueType SHT_Get(HashTable* HT, KeyType Key){
	int adress = SHT_Hash(Key, HT->TableSize);
	
	return HT->Table[adress].Value;
}

void SHT_DestroyHashTable(HashTable* HT){
	free(HT->Table);
	free(HT);
}

int SHT_Hash (KeyType Key, int TableSize){
	return Key % TableSize;
}
