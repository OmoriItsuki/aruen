#include <stdio.h>

int main(void){

    int a[3];
    int *p;
    int tmp;
    
    printf("a[0]の値を入力してください:");scanf("%d",&a[0]);
    printf("a[1]の値を入力してください:");scanf("%d",&a[1]);
    printf("a[2]の値を入力してください:");scanf("%d",&a[2]);
    p=a;
    
    int min=p[0]<p[1]?0:1;
    min=p[min]<p[2]?min:2;
	
    int t=p[0];
    p[0]=p[min];
    p[min]=t;
	
    min=p[1]<p[2]?1:2;
    t=p[1];
    p[1]=p[min];
    p[min]=t;
    
    printf("a[]: %d %d %d\n",a[0],a[1],a[2]);
}
