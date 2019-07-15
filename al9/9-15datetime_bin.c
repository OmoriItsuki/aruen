#include<stdio.h>
#include<time.h>

int main(void){
	struct tm *tm;
	time_t t;
	time(&t);
	tm=localtime(&t);
	
	FILE *fp;
	fp=fopen("datetime.dat", "w");
	fwrite(&tm->tm_year, 4, 1, fp);
	
	fclose(fp);
}
