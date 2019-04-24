#include <stdio.h>
#define MAX_STUDENT 20

int main(void){
	int n;
	printf("学生数を入力してください ");
	printf("input k:");
	scanf("%d\n",&n);
	while(n<=0|MAX_STUDENT<n){
		printf("1~20の数字を入力してください");
	    printf("学生数を入力してください/n");
		printf("input k:");
	    scanf("%d\n",&n);
		}
	
	int point,class[5];
	for(int i=0;i<n;i++){
		printf("%d人目の点数を入力してください:",i+1);
		scanf("%d\n",&point);
		int c = (point-50)/10;
		c = c < 0? 0:
		    4 < c? 4: c;
		class[c]++;
		}
		
	printf("\n");
	printf("60点未満の学生は%d名です。\n",class[0]);	
	for(int i=1;i<4;i++)
	{
		printf("%d点以上%d点未満の学生は%d名です。\n",50+10*i,60+10*i,class[i]);
	}
	printf("90点以上の学生は%d名です。\n",class[4]);
	
	}
