#include <stdio.h>

int count_bits(unsigned x){
    int bits=0;
    while(x){
        bits++;
        x>>=1;
    }
    return bits;
}

void print_bit(int x){
	for(int i=count_bits(x)-1;i>=0;i--){
			putchar((x>>i)&1?'1':'0');
		}
	}
	
int main(void){
	int x;
	printf("xの値を入力してください:");
	scanf("%d\n",&x);
	printf("xの2進数表記:0b");print_bit(x);printf("\n");
	printf("xの8進数表記:0o%o\n",x);
	printf("xの16進数表記:0x%x\n",x);
	}
