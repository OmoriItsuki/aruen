#include<stdio.h>


int input_score();
void input_multiple_scores(int num,int *a);


void main(){
	int score[10];
	int num=10;
	input_multiple_scores(num,score);
	int sum=0;
	int max=score[0];
	for(int i = 0; i < num; i++)
	{
		max=max>score[i]?max:score[i];
		sum+=score[i];
	}
	sum/=num;
	printf("平均点は%d点、最高点は%d点です。\n",sum,max);
	
}

int input_score(){
	int a;
	printf("Input : ");
	scanf("%d",&a);

	return a;
}

void input_multiple_scores(int num,int *a){
	for(int i = 0; i < num; i++)
	{
		while(1){
			a[i] = input_score();
			if(*a <= 100 && *a>= 0)
				break;
			else printf("再入力してください\n");
		}
	}
}