#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *fp;
	int chr;
	
	fp=fopen("anne_short.txt","r");
	if(fp==NULL){
		printf("そのファイルは存在しません。\n");
		return -1;
	}
	
	while((chr = fgetc(fp))!= EOF){
		putchar(chr);
	}
	
	fclose(fp);
	return 0;
}
