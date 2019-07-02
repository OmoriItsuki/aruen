#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct word
{
    char name[20];
    struct word *next;
};
typedef struct word Word;

int read_word(FILE *fp,char *buf){
    int c;
    int k=0;
    for (int i = 0; buf[i]!='\0'; i++)
        {
            buf[i]='\0';
        }
    while ((c=fgetc(fp))!=EOF)
        {
            switch (c)
            {
            case 32:
                return k;
                break;
            case 44:
            case 46:
                break;
            default:
                buf[k]=c;
                k++;
                break;
            }
        }
        return 0;
}

void print_nodes(Word *root){
    Word *tmp=root;
    do{
        printf("%s ",tmp->name);
    }while((tmp=tmp->next)!=NULL);
    putchar('\n');
}

Word *add_node(char *buf,Word *root){
    Word *p=malloc(sizeof(Word));
    Word *tmp=NULL;
    if(p!=NULL){
        if(root==NULL){
            root=p;
            p=malloc(sizeof(Word));
            tmp=root;
        }else{
            tmp=root;       
            while(tmp->next!=NULL){
                tmp=tmp->next;
            }
        }
        tmp->next=p;
        p->next=NULL;
        strcpy(p->name,buf);
    }
    return root;
}

void main(){
    Word *root=NULL;
    char buf[20];
    FILE *fp;

    fp=fopen("anne_short.txt","r");
    if(fp==NULL){
        printf("FIle read error!\n");
        return;
    }

    while (read_word(fp,buf)>0)
    {
        root=add_node(buf,root);
    }
    print_nodes(root);
    fclose(fp);
}