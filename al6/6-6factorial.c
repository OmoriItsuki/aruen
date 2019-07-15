#include <stdio.h>

int main(void){
    int n;
    printf("整数を入力してください:");
    scanf("%d/n",&n);
    
    int m=n,f=1;
    while(m>0){
        f*=m;
        m--;
    }
    printf("%dの階乗は%dです。",n,f);
	}