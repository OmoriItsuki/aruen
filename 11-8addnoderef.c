#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct word
{
    char name[20];
    struct word *next;
    int count;
};
typedef struct word Word;

Word *create_word(){
    return malloc(sizeof(Word));
}

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
            case 13:
            case 10:
                break;
            default:
                buf[k]=c;
                //printf("%c %s %d\n",c,buf,k);
                k++;
                break;
            }
        }
        return 0;
}

void print_nodes(Word *root){
    Word *tmp=root->next;
    do{
        printf("%13s %2d\n",tmp->name,tmp->count);
    }while((tmp=tmp->next)!=NULL);
}

Word *add_node(char *buf,Word *root){
    Word *tmp=NULL;
    Word *p;
    //初回処理
    if(root==NULL){
        root=create_word();
    }
    tmp=root;
    do{
        //最も後ろに挿入する場合
        if(tmp->next==NULL){
            p=create_word();
            strcpy(p->name,buf);
            p->next=NULL;
            tmp->next=p;
            p->count=1;
            return root;
        //線形リストに一致するデータがあった場合
        }else if(strcmp(buf,(tmp->next)->name)==0){
            tmp->next->count++;
            return root;
        //tmpとtmp->nextの間に挿入すべき場合
        }else if(strcmp(buf,(tmp->next)->name)<0){
            p=create_word();
            strcpy(p->name,buf);
            p->count=1;
            p->next=tmp->next;
            tmp->next=p;
            return root;
        }
        tmp=tmp->next;
    }while(tmp!=NULL);
    return root;
}

void free_nodes(Word *root){
    Word *tmp=root;
    while (tmp->next!=NULL)
    {
        root=tmp;
        tmp=tmp->next;
        free(root);
    }
    
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
        //printf("%s\n",buf);
        root=add_node(buf,root);
    }
    print_nodes(root);
    fclose(fp);
    free_nodes(root);
}