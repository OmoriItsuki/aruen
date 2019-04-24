#include <stdio.h>
int put_count(void){
	static int count=0;
	count++;
	return count;
}

int main(void){
    for(int i=0;i<5;i++){
        printf("put_count: %d回目\n",put_count());
    }
}
