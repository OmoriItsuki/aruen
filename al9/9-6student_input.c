#include <stdio.h>

typedef struct{
	char name[32];
	float height;
	float weight;
	float bmi;
	}Student;
	
Student student_input(){
	Student s;
	printf("名前:");scanf("%s\n",&s.name);
	printf("身長:");scanf("%f\n",&s.height);
	printf("体重:");scanf("%f\n",&s.weight);
	s.bmi=s.weight*10000/s.height/s.height;
	return s;
	}
	
void print_student(Student p){
		printf("Name:%s,Height:%.0f,Weight:%.1f,BMI:%.2f\n",p.name,p.height,p.weight,p.bmi);
	}
	
int main(void){
	Student s=student_input();
	print_student(s);
	}
