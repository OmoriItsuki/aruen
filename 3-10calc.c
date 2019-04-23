#define MAX_STUDENTS 20
#include<stdio.h>

void main(){
	int a;
	int point;
	int count[5]={0,0,0,0,0};
	do{
		printf("学生数を入力してください：");
		scanf("%d",&a);
	}while(a<=0 || a>MAX_STUDENTS);


	for(int i=1;i<=a;i++){
		do{
			printf("%d人目の点数を入力してください：",i);
			scanf("%d",&point);
			if(point<=100 && point>=0)
				break;
		}while(1);
		
		point/=10;	

		switch(point){
			case 6:count[1]++;
			       break;
			case 7:count[2]++;
			       break;
			case 8:count[3]++;
			       break;
			case 9:
			case 10:
			       count[4]++;
			       break;
			default:
			       count[0]++;
			       break;
		}
	}

	printf("\n60点未満の学生は%d名です。\n",count[0]);
	printf("60点以上70点未満の学生は%d名です。\n",count[1]);
	printf("70点以上80点未満の学生は%d名です。\n",count[2]);
	printf("80点以上90点未満の学生は%d名です。\n",count[3]);
	printf("90点以上の学生は%d名です。\n",count[4]);
}

	
