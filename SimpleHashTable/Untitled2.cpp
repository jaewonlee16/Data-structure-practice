#include "SimpleHashTable.h"

int main(){
	HashTable* HT = SHT_CreateHashTable(193);
	
	SHT_Set(HT, 418, 32114);
	SHT_Set(HT, 9, 32114);
	SHT_Set(HT, 427, 32114);
	SHT_Set(HT, 1031, 32114);
	
	// print
	
	
	return 0;
}
