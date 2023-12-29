#include <stdio.h>
#include <string.h>
#include "KarpRabin.h"

#define MAX_BUFFER 512

int main(int argc, char** argv){
	char* FilePath;
	FILE* fp;
	
	char Text[MAX_BUFFER];
	char* Pattern;
	int PatternSize = 0;
	int Line = 0;
	
	if (argc < 3){
		printf("filePath");
		return 1;
	}
	
	FilePath = argv[1];
	Pattern = argv[2];
	
	PatternSize = strlen(Pattern);
	
	if ((fp = fopen(FilePath, "r")) == NULL){
		printf("Cannot open File");
		return 1;
	}
	
	while (fgets(Text, MAX_BUFFER, fp) != NULL){
		int position = KarpRabin(Text, strlen(Text), 0, Pattern, PatternSize);
		
		Line++;
		
		if (position >= 0)
			printf("line: %d, column: %d : %s", Line, position + 1, Text);
	}
	
	fclose(fp);
}
