﻿#include <stdio.h>
#include <stdlib.h>

struct prefecture{
	char name[16];
	int area;
	int population;
	double density;
	};

void ssort(struct prefecture *p,int l){
	int s=0;
	while(s<l)
	{
		int max =s;
		for(int i=s;i<l;i++)
		{
			max=p[max].density>p[i].density?max:i;
		}
		struct prefecture t=p[s];
		p[s]=p[max];
		p[max]=t;
		s++;
	}
	}
		
int main(void){
	FILE *fp;
	int chr;
	
	fp=fopen("prefectures.txt","r");
	if(fp==NULL){
		printf("そのファイルは存在しません。\n");
		return -1;
	}

	struct prefecture prefectures[47];
	for(int i=0;i<47;i++)
	{
		char name[16];
		int area,population;
		fscanf(fp, "Name:%s Area:%d Population:%d\n",
		&prefectures[i].name,
		&prefectures[i].area,
		&prefectures[i].population);
		prefectures[i].density=
		(double)prefectures[i].population/(double)prefectures[i].area;
	}
	
	ssort(prefectures, 47);
	for(int i=0;i<47;i++)
	{
	    printf("都道府県名:%s, 面積:%d(km^2), 人口:%d(人), 人口密度:%.02lf(人/km^2)\n",
		prefectures[i].name,
		prefectures[i].area,
		prefectures[i].population,
		prefectures[i].density);
	}
	
	fclose(fp);
	return 0;
}
