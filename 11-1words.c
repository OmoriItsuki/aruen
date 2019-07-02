#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
                k++;
                break;
            }
        }
        return 0;
}

void main(){
    char *words[400];
    char buf[20];
    FILE *fp;
    int b,k=0;

    fp=fopen("anne_short.txt","r");
    if(fp==NULL){
        printf("FIle read error!\n");
        exit(1);
    }
    
    while ((b=read_word(fp,buf)>0))
    {
        words[k]=malloc(b);
        strcpy(words[k],buf);
        k++;
    }
    
    for (int i = 0; words[i]!=NULL; i++)
    {
        printf("%s\n",words[i]);
    }
    

    /*
    while (read_word(fp,buf)>0)
    {
        printf("%s\n",buf);
    } */
    fclose(fp);
    
}