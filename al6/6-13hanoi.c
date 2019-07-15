#include <stdio.h>
#define FORMAT "円盤[%d]を棒%cから棒%cへ移動する\n"

void hanoi(int n,char from,char to,char other){
	if(n>1)hanoi(n-1,from, other, to);
	printf(FORMAT,n,from,to);
	if(n>1)hanoi(n-1, other, to, from);
	}
	
int main(void){
	int num_disk=4;
	hanoi(num_disk,'A','C','B');
	}