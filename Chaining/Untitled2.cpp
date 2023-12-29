#include "Chaining.h";

int main(){
	HashTable* HT = CHT_CreateHashTable(12289);
	
	CHT_Set(HT, "MSFT", "Microsoft");
	CHT_Set(HT, "JAVA", "Microsoft");
	CHT_Set(HT, "REDH", "Microsoft");
	CHT_Set(HT, "APAC", "Microsoft");
	CHT_Set(HT, "ZYMZZ", "Microsoft");
	CHT_Set(HT, "IBM", "Microsoft");
	CHT_Set(HT, "ORCL", "Microsoft");
	CHT_Set(HT, "CSCO", "Microsoft");
	CHT_Set(HT, "GOOG", "Microsoft");
	
	printf("%s,  %s", "MSFT", CHT_Get(HT, "MSFT"));
	
}
