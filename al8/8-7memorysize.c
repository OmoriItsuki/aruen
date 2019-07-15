#include <stdio.h>
int main(void){
    char a[][5]={"LISP","C","Ada"};
    char *p[] ={"PAUL","X","MAC"};
    
    int asum=0,psum=0;
    for(int i=0;i<3;i++){
        asum+=sizeof(a[i]);
        psum+=sizeof(p[i]);
        }
    
    printf("2次元配列aを用いる方法では、3単語を記憶するために%dバイトを占有している。\n",asum);
    printf("ポインタの配列pを用いる方法では、3単語を記憶するために%dバイトを占有している。\n",psum);
}
