#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct prefecture{
	char name[16];
	int area;
	int population;
	double density;
	};
	
int n_index(struct prefecture *p,int a,int b){
	return strcmp(p[a].name, p[b].name)<0?a:b;
	}
int a_index(struct prefecture *p,int a,int b){
	return p[a].area>p[b].area?a:b;
	}
int p_index(struct prefecture *p,int a,int b){
	return p[a].population>p[b].population?a:b;
	}
int d_index(struct prefecture *p,int a,int b){
	return p[a].density>p[b].density?a:b;
	}
		
void ssort(struct prefecture *p,int l,int (*func)(struct prefecture *p,int,int)){
	int s=0;
	while(s<l)
	{
		int max =s;
		for(int i=s;i<l;i++)
		{
			max=func(p,max,i);
		}
		struct prefecture t=p[s];
		p[s]=p[max];
		p[max]=t;
		s++;
	}
	}
		
int main(int argc,char *argv[]){
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
	
	switch(argv[1])
	{
		case "name":ssort(prefectures, 47, n_index);break;
		case "area":ssort(prefectures, 47, a_index);break;
		case "popuration":ssort(prefectures, 47, p_index);break;
		case "density":ssort(prefectures,47,d_index);break;
		default:printf("コマンドがありません\n");return 0;
	}
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
