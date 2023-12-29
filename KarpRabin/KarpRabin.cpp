#include "KarpRabin.h"
#include <stdio.h>
#include <math.h>

int KarpRabin (char* Text, int TextSize, int Start, char* Pattern, int PatternSize){
	int HashText = Hash (Text, PatternSize);
	int HashPattern = Hash (Pattern, PatternSize);
	
	int coefficient = pow (2.0, PatternSize - 1);
	
	for (int i = Start; i <= TextSize - PatternSize; i++){
		HashText = Rehash(Text, i, PatternSize, HashText, coefficient);
		
		int j;
		if (HashPattern == HashText){
			printf("samehash %d\n", i);
			for (j = 0; j < PatternSize; j++){
				if (Pattern[i + j] != Text[i + j])
					break;
			}
			
			if (j >= PatternSize)
				return i;
		}
	}
	
	return -1;
}

int Hash (char* String, const int Size){
	int HashValue = 0;
	
	for (int i = 0; i < Size; i++){
		HashValue += String[i] * pow(2.0, Size - 1 - i);
	}
	
	return HashValue;
}

int Rehash (char* String, const int Start, const int Size, int HashPrev, int Coefficient){
	if (Start == 0)
		return HashPrev;
		
	return 2 * (HashPrev - Coefficient * String[Start - 1]) + String[Start + Size - 1];
}
