#include <stdio.h>
	

int count_bits(unsigned x){
    int bits=0;
    while(x){
        if(x&1) bits++;
        x>>=1;
    }
    return bits;
}

int int_bits(void){
    return count_bits(~0);
}

void print_bit(int x){
	for(int i=int_bits()-1;i>=0;i--){
		putchar((x>>i)&1?'1':'0');
	}
	}
	
int main(void){
	unsigned x,y;
	printf("xの値を入力してください:");
	scanf("%d\n",&x);
	printf("yの値を入力してください:");
	scanf("%d\n",&y);
	
	printf("xの2進数表記は");print_bit(x);printf("です。\n");
	printf("yの2進数表記は");print_bit(y);printf("です。\n");
	printf("xとyのANDは");print_bit(x&y);printf("です。\n");
	printf("xとyのORは");print_bit(x|y);printf("です。\n");
	printf("xとyのXORは");print_bit(x^y);printf("です。\n");
	}
