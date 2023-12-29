#include "OpenAddressing.h"

int main(){
	HashTable* HT = OAHT_CreateHashTable(11);
	
	OAHT_Set(&HT, "MSFT", "Microsoft");
	OAHT_Set(&HT, "JAVA", "Mdggd");
	OAHT_Set(&HT, "REDH", "Mkjkj");
	OAHT_Set(&HT, "APAC", "Mdsfdst");
	OAHT_Set(&HT, "ZYMZZ", "Mqwert");
	OAHT_Set(&HT, "IBM", "dsf");
	OAHT_Set(&HT, "ORCL", "Mighgt");
	OAHT_Set(&HT, "CSCO", "Mghhg");
	OAHT_Set(&HT, "YHOO", "Mghj");
}
