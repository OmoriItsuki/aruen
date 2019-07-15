#include<stdio.h>
#include<time.h>

int main(void){
	struct tm *tm;
	time_t t;
	char *wday[] = {"日","月","火","水","木","金","土"};
	time(&t);
	tm=localtime(&t);
	
	printf("読み出した日時は、%d年%d月%d日%s %d時%d分%d秒です。",
	tm->tm_year+1900,
	tm->tm_mon+1,
	tm->tm_mday,
	wday[tm->tm_wday],
	tm->tm_hour,
	tm->tm_min,
	tm->tm_sec);
}