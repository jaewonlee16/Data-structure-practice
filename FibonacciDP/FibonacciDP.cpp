#include <stdio.h>
#include <stdlib.h>

unsigned int long Fibonacci (int N);

int main(){
	int n = 46;
	unsigned int Result = Fibonacci(n)	;
	
	printf("Fibonacci(%d): %lu\n", n, Result);
	
	return 0;
}

unsigned int long Fibonacci (int N){
	if ( N == 0 || N == 1)
		return N;
		
	unsigned int long* FibonacciTable;
	unsigned int long Result;
	
	FibonacciTable = (unsigned int long*)malloc(sizeof(unsigned int long) * (N + 1));
	
	FibonacciTable[0] = 0;
	FibonacciTable[1] = 1;
	
	for (int i = 2; i <= N; i++){
		FibonacciTable[i] = FibonacciTable[i - 1] + FibonacciTable[i - 2];
	}
	
	Result = FibonacciTable[N]	;
	
	free(FibonacciTable);
	
	return Result;
}

