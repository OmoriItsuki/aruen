#include <stdio.h>
int main(void){ 
	int a,n0=0,sum=0;
	do{
	  printf("Input a:");
	  scanf("%d\n",&a);
	  if(0<=a&a<=10){
	      printf("入力された数は%dです\n",a);
	      if(a==0)n0++;
	      sum+=a;
	  }else{
	      printf("0〜10の範囲で入力してください。\n");
	  }
	}while(a!=10);
	printf("0は%d回入力されました。\n入力された値の合計は%dです。\n",n0,sum);
}