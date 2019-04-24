#include <stdio.h>

void put_chars(char c,int n){
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            if(i<=j){
                printf("%c",c);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(void){
    int n;
    printf("正の整数:");
    scanf("%d\n",&n);
    char c='*';
    put_chars(c,n);
}