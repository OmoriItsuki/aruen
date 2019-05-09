#include<stdio.h>

void print_bits(unsigned int a) {
	unsigned int c = 1U;
	do {
		putchar(a & c ? '1' : '0');
	} while (a >>= 1);
	putchar('\n');
}


void main(){
	char a;
	unsigned int s;
	printf("a:");
	scanf("%s",&a);
	s = a;
	print_bits(s);
	//print_bits(a);
}

