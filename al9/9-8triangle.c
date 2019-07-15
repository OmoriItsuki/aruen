#include <stdio.h>
#include <math.h>

typedef struct {
	double x;
	double y;
	}Point;
	
double length(Point p1,Point p2){
	double x=p1.x-p2.x;
	double y=p1.y-p2.y;
	return sqrt(x*x+y*y);;
	}

double diff(double l1,double l2,double l3){
	return l1>l2?
	(l2>l3?l1-l3:
	(l1>l3?l1-l2:l3-l2)):
	(l1>l3?l2-l3:
	(l2>l3?l2-l1:l3-l1));
	}

Point input_point(char pn[]){
	Point p;
	printf("点%sのx座標:",pn);scanf("%lf\n",&p.x);
	printf("点%sのy座標:",pn);scanf("%lf\n",&p.y);
	return p;
	}
	
int main(void){
	Point p1=input_point("p1");
	Point p2=input_point("p2");
	Point p3=input_point("p3");
	
	printf("この三角形は%s",diff(length(p1, p2), length(p2, p3), length(p3, p1))<0.1?"正三角形です。":"正三角形ではありません。");
	}
