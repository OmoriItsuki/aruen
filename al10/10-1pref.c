#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *fp;
	int chr;
	
	fp=fopen("prefectures.txt","r");
	if(fp==NULL){
		printf("そのファイルは存在しません。\n");
		return -1;
	}

	for(int i=0;i<47;i++)
	{
		char name[16];
		int area,population;
		fscanf(fp, "Name:%s Area:%d Population:%d\n",&name,&area,&population);
		double density=(double)population/(double)area;
		printf("都道府県名:%s, 面積:%d(km^2), 人口:%d(人), 人口密度:%.02lf(人/km^2)\n",name,area,population,density);
	}
	
	fclose(fp);
	return 0;
}
