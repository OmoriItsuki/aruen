#include <stdio.h>

int main(void){
	char c;
	printf("文字を入力してください:");scanf("%c\n",&c);
	printf("%cにJISコードは、10進数では%d、16進数では0x%xです。",c,c,c);
	}
