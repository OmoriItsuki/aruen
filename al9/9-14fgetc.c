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
	
	FILE *w;
	w=fopen("anne_word.txt", "w");
	while((chr = fgetc(fp))!= EOF){
		switch(chr)
		{
			case ' ':fputc('\n', w);break;
			case ',':
			case '.':break;
			default:fputc(chr, w);
		}
	}
	
	fclose(fp);
	fclose(w);
	return 0;
}
