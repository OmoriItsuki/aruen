#include<stdio.h>

int score[10];
int input_score();
void input_multiple_scores(int num);


void main(){
	int num=10;
	input_multiple_scores(num);
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

void input_multiple_scores(int num){
	for(int i = 0; i < num; i++)
	{
		while(1){
			score[i]=input_score();
			if(score[i]<=100 && score[i]>= 0)
				break;
			else printf("再入力してください\n");
		}
	}
	
	
}