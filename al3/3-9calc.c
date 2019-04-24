#include <stdio.h>
#define NUM_ELEMENTS 10

int main(void){
   
   int ary[NUM_ELEMENTS]={72,74,50,71,77,84,61,90,73,75}; 
   
   int max=ary[0],min=ary[0];
   float ave=0,ver=0;
   for(int i=0;i<NUM_ELEMENTS;i++){
       max=max>ary[i]?max:ary[i];
       min=min<ary[i]?min:ary[i];
       ave+=ary[i];
   }
   
   ave/=NUM_ELEMENTS;
   
   for(int i=0;i<NUM_ELEMENTS-1;i++){
       ver+=(ary[i]-ave)*(ary[i]-ave);
   }
   ver/=NUM_ELEMENTS;
   
   printf("%d\n",max);
   printf("%d\n",min);
   printf("%.3f\n",ave);
   printf("%.3f\n",ver);
}