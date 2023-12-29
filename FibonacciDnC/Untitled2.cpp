#include "Fibonacci.h"

int main(){
	int n = 46;
	
	unsigned int Result = Fibonacci(n);
	
	printf("Fibonacci(%d) = %lu\n", n, Result);
	
	return 0;
}
