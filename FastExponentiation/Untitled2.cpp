#include <stdio.h>

unsigned long long Power (int Base, int Exponent);

int main(){
	int base = 2;
	int exponent = 30;
	
	printf("%lu\n", Power(base, exponent));
	return 0;
}

unsigned long long Power (int Base, int Exponent){
	if (Exponent == 0)
		return 1;
	else if (Exponent == 1)
		return Base;
		
	if (Exponent % 2 == 0){
		unsigned long long NewBase = Power (Base, Exponent / 2);
		return NewBase * NewBase;
	}
	
	else{
		unsigned long long NewBase = Power (Base, (Exponent - 1) / 2);
		return NewBase * NewBase * Base;
	}
}
