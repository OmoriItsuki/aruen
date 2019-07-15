#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *fp;
	
	fp=fopen("exec_count.txt","r");
	if(fp==NULL){
		printf("このプログラムは初めて実行されました。\n");
	    fclose(fp);
		fp=fopen("exec_count.txt","w");
		fprintf(fp, "%d",1);
	    fclose(fp);
	    return 0;
	}
	
	unsigned n;
	fscanf(fp, "%u",&n);
	fclose(fp);
	fp=fopen("exec_count.txt","w");
	fprintf(fp, "%u",n+1);
	printf("このプログラムが実行されたのは%u回目です。\n",n+1);
	fclose(fp);
	return 0;
}
