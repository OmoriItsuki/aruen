#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_X 20
#define SIZE_Y 10
int start_x;
int start_y;

void read_map(char map[SIZE_Y][SIZE_X]){
	FILE *fp;
	fp=fopen("meiro1.txt", "r");
	if(fp==NULL){
		printf("File read error\n");
		exit(1);
		return;
		}
	char chr;
	for(int i=0;i<SIZE_Y;i++){
		int j=0;
		while(j<SIZE_X){
			chr=fgetc(fp);
			if(chr!='\n'){
				map[i][j]=chr;
				if(chr=='S'){
					start_x=j;
					start_y=i;
				}
				j++;
			}else{
				continue;
			}
		}
	}
	}

int positive_min(int a,int b){
	if(a<0){
		if(b<0)return -1;
		else return b;
	}else{
		if(b<0)return a;
		else return a>b?a:b;	
	}	
}

int recursive_search(char map[SIZE_Y][SIZE_X],int x, int y){
	
	if(map[y][x]=='G'){
		return 0;
	}else if ((map[y][x]=='#')||( map[y][x]=='.')){
		return -1;
	}else{
		map[y][x]='.';
		int n=positive_min(recursive_search(map,x,y-1),recursive_search(map,x,y+1));
		n=positive_min(n,recursive_search(map,x-1,y));
		n=positive_min(n,recursive_search(map,x+1,y));
		return n<0?-1:n+1;
	}
}

int main(void){
	char map[SIZE_Y][SIZE_X];
	read_map(map);
	printf("%d\n",recursive_search(map,start_x,start_y));
	}
