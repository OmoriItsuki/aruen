#include<stdio.h>

void main(){
	int k;
	int ans=1;
	printf("Input k:");
	scanf("%d",&k);

	for(int i=1;i<=k;i++){
		ans*=i;
	}
	printf("%d\n",ans);
}
