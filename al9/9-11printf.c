#include<stdio.h>
#include<time.h>

int main(void){
	struct tm *tm;
	time_t t;
	time(&t);
	tm=localtime(&t);
	
	printf("%d %d %d %d %d %d %d",
	tm->tm_hour,
	tm->tm_min,
	tm->tm_sec,
	tm->tm_year%100,
	tm->tm_mon+1,
	tm->tm_mday,
	tm->tm_wday);
}