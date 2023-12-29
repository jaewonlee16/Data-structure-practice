#include "BruteForce.h"

int BruteForce(char* Text, int TextSize, int Start, char* Pattern, int PatternSize){
	for (int i = Start; i < TextSize - PatternSize; i++){
		int j;
		for (j = 0; j < PatternSize; j++){
			if (Text[i + j] != Pattern[j])
				break;
		}
		if (j >= PatternSize)
			return i;
	}
	return -1;
}
