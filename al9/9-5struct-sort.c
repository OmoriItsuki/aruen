#include <stdio.h>

typedef struct{
	char name[32];
	float height;
	float weight;
	float bmi;
	int scholarship;
	}Student;
	
void print_student(Student s1,Student s2,Student s3){
	printf("奨学金の金額が高い順に表示します。\n");
	printf("Name:%s,Height:%.0f,Weight:%.1f,BMI:%.2f,Scholarship:%d\n",s1.name,s1.height,s1.weight,s1.bmi,s1.scholarship);
	printf("Name:%s,Height:%.0f,Weight:%.1f,BMI:%.2f,Scholarship:%d\n",s2.name,s2.height,s2.weight,s2.bmi,s2.scholarship);
	printf("Name:%s,Height:%.0f,Weight:%.1f,BMI:%.2f,Scholarship:%d\n",s3.name,s3.height,s3.weight,s3.bmi,s3.scholarship);
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
		
	Student  s1=tanaka,s2=suzuki,s3=sato;
	if(s1.scholarship<s2.scholarship)swap(&s1, &s2);
	if(s2.scholarship<s3.scholarship)swap(&s2, &s3);
	if(s1.scholarship<s2.scholarship)swap(&s1, &s2);
	
	print_student(s1,s2,s3);
	}
