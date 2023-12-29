#ifndef LCS_H
#define LCS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _LCSTable{
	int** Data;
}LCSTable;

int LCS (char* X, char* Y, int i, int j, LCSTable* Table);

void LCS_TraceBack (char* X, char* Y, int m, int n, LCSTable* Table, char* LCS);

void LCS_PrintTable (LCSTable* Table, char* X, char* Y, int LEN_X, int LEN_Y);

#endif
