#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char name[32];
	float height;
	float weight;
	float bmi;
	int scholarship;
	}Student;
	
void print_student(Student *p,int l){
	printf("奨学金の金額が高い順に表示します。\n");
	for(int i=0;i<3;i++)
	{
		printf("Name:%s,Height:%.0f,Weight:%,BMI:%.2f,Scholarship:%d\n",p[i].name,p[i].height,p[i].weight,p[i].bmi,p[i].scholarship);
	}
	}
	
void swap(Student *p1,Student *p2){
	Student tmp=*p1;
	*p1=*p2;
	*p2=tmp;
	}
	
int main(void){
	FILE *fp;
	
	fp=fopen("student.txt","r");
	if(fp==NULL){
		printf("そのファイルは存在しません。\n");
		return -1;
	}
	
	Student person[3];
	for(int i=0;i<3;i++)
	{
		fscanf(fp, "Name:%s,Height:%f,Weight:%f,Scholarship:%d\n",&person[i].name,&person[i].height,&person[i].weight,&person[i].scholarship);
		person[i].bmi=person[i].weight*10000/(person[i].height*person[i].height);
	}
		
	if(person[0].scholarship<person[1].scholarship)swap(&person[0], &person[1]);
	if(person[1].scholarship<person[2].scholarship)swap(&person[1], &person[2]);
	if(person[0].scholarship<person[1].scholarship)swap(&person[0], &person[1]);
	
	print_student(person,3);
	fclose(fp);
	}
