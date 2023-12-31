#ifndef SIMPLEHASHTABLE_H
#define SIMPLEHASHTABLE_H

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int ValueType;

typedef struct _Node{
	KeyType Key;
	ValueType Value;
}Node;

typedef struct _HashTable{
	int TableSize;
	Node* Table;
}HashTable;

HashTable* SHT_CreateHashTable(int TableSize);
void SHT_Set(HashTable* HT, KeyType Key, ValueType Value);
ValueType SHT_Get(HashTable* HT, KeyType Key);
void SHT_DestroyHashTable(HashTable* HT);
int SHT_Hash (KeyType Key, int TableSize);

#endif
