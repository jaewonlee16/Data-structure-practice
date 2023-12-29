#include "LCS.h"

int main(){
	char* X = "GOOD MORNING.";
	char* Y = "GUTEN MORGEN.";
	char* Result;
	
	int LEN_X = strlen(X);
	int LEN_Y = strlen(Y);
	
	LCSTable Table;
	
	Table.Data = (int**)malloc(sizeof(int*) * (LEN_X + 1));
	
	for (int i = 0; i < LEN_X + 1; i++){
		Table.Data[i] = (int*)malloc(sizeof(int) * (LEN_Y + 1));
		
		memset(Table.Data[i], 0, sizeof(int) * (LEN_Y + 1));
	}
	
	int Length = LCS(X, Y, LEN_X, LEN_Y, &Table);
	
	LCS_PrintTable(&Table, X, Y, LEN_X, LEN_Y);
	
	Result = (char*)malloc(sizeof(Table.Data[LEN_X][LEN_Y] + 1));
	sprintf(Result, "");
	
	LCS_TraceBack(X, Y, LEN_X, LEN_Y, &Table, Result);
	
	printf("\n");
	printf("LCS:\"%s\" (Length: %d) \n", Result, Length);
	
	return 0;
	
}
