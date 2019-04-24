#include <stdio.h>
int main(void){ 
	int a=0;
	while(a<=10|20<=a){
	  printf("Input a:");
	  scanf("%d\n",&a);
	  if(a<=10|20<=a){
	      printf("10〜20の範囲で入力してください。\n");
	  }
	}
	for(int i=0;i<a*2;i++){
	    printf("+");
	}
}