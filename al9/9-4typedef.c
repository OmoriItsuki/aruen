#include <stdio.h>

typedef struct{
	char name[32];
	float height;
	float weight;
	float bmi;
	int scholarship;
	}Student;
	
void print_student(Student *p,int l){
	printf("BMIを高い順に表示します。\n");
	for(int i=0;i<3;i++)
	{
		printf("Name:%s,Height:%.0f,Weight:%.1f,BMI:%.2f,Scholarship:%d\n"
		,p[i].name,p[i].height,p[i].weight,p[i].bmi,p[i].scholarship);
	}
	}
	
void swap(Student *p1,Student *p2){
	Student tmp=*p1;
	*p1=*p2;
	*p2=tmp;
	}
	
int main(void){
	Student tanaka={"Tanaka",160,55.8,0,58000},
	suzuki={"Suzuki",185,86.2,0,63000},
	sato={"Sato",172,77.5,0,75000};
	tanaka.bmi=tanaka.weight*10000/tanaka.height/tanaka.height;
	suzuki.bmi=suzuki.weight*10000/suzuki.height/suzuki.height;
	sato.bmi=sato.weight*10000/sato.height/sato.height;
		
	Student  person[3]={tanaka,suzuki,sato};
	if(person[0].bmi<person[1].bmi)swap(&person[0], &person[1]);
	if(person[1].bmi<person[2].bmi)swap(&person[1], &person[2]);
	if(person[0].bmi<person[1].bmi)swap(&person[0], &person[1]);
	
	print_student(person,3);
	}
