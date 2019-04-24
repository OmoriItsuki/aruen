#include <stdio.h>
int sum(int n){
    return n*(n+1)/2;
}

int main(void){
    int n;
    printf("input n:");
    scanf("%d\n",&n);
    printf("%d",sum(n));
}
