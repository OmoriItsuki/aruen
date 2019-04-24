#include <stdio.h>
int main(void){ 
	int a=-1;
	while(a<=10|20<=a){
	  printf("Input a:");
	  scanf("%d\n",&a);
	  if(a<=10|20<=a){
	      printf("10〜20の範囲で入力してください。\n");
	  }
	}
	a*=2;
	while(a>0){
	    printf("+");
	    a--;
	}
}