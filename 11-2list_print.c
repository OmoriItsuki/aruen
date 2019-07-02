#include<stdio.h>

struct word
{
    char name[20];
    struct word *next;
};typedef struct word Word;

void print_nodes(Word *root){
    Word *tmp=root;
    do{
        printf("%s ",tmp->name);
    }while((tmp=tmp->next)!=NULL);
    putchar('\n');
}

void main(){
    Word *root=NULL;

    Word node1={"one",NULL};
    Word node2={"two",NULL};
    Word node3={"three",NULL};

    root=&node1;
    node1.next=&node2;
    node2.next=&node3;
    print_nodes(root);
}