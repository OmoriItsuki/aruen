#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_X 20
#define SIZE_Y 10

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
				j++;
			}else{
				continue;
			}
		}
	}
	}
	
void print_map(char map[SIZE_Y][SIZE_X]){
		for (int i = 0; i < SIZE_Y; i++)
		{
			for(int j=0;j<SIZE_X;j++){
				putchar(map[i][j]);
			}
			putchar('\n');
		}
	}
	
int main(void){
	char map[SIZE_Y][SIZE_X];
	read_map(map);
	print_map(map);
	}
