#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *fp;
    char *filename="anne_short.txt";

    if((fp=fopen(filename,"rgcc"))==NULL){
        fprintf(stderr, "そのファイルは存在しません。\n",filename);
        exit(EXIT_FAILURE);
    }
}