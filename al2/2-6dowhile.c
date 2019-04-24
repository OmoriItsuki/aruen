#include <stdio.h>
int main(void){ 
	int a;
	do{
	  printf("Input a:");
	  scanf("%d\n",&a);
	  if(0<=a&a<=10){
	      printf("入力された数は%dです\n",a);
	  }else{
	      printf("0〜10の範囲で入力してください。\n");
	  }
	}while(a!=10);
}
