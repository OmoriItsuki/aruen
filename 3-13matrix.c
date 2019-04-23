#include<stdio.h>

void main(){
	int list1[2][3];
	int list2[3][2];
	int list3[2][2]={{0,0},{0,0}};
	char str[2][2]={"A","B"};

	for(int i=0;i<2;i++){
		for(int k=0;k<(i==0?2:3);k++){
			printf("行列%s(%d行%d列)の%d行目を入力してください：",str[i],i==0?2:3,i==0?3:2,k+1);
			if(i==0)
				scanf("%d %d %d",&list1[k][0],&list1[k][1],&list1[k][2]);
			else
				scanf("%d %d",&list2[k][0],&list2[k][1]);
		}
	
	}
	for(int i=0;i<2;i++){
		for(int k=0;k<2;k++){
			for(int j=0;j<3;j++){
				list3[i][k]+=list1[i][j]*list2[j][k];
			}
		}
	
	}
	printf("AとBの積は以下です。\n");
	printf("%5d %5d \n%5d %5d\n",list3[0][0],list3[0][1],list3[1][0],list3[1][1]);

		
}
