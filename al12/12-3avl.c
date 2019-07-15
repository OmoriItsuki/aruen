#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word{
	struct word *left;
	struct word *right;
	int height;
	int count;
	char name[20];
	};
typedef struct word Word;
	
int read_word(FILE *fp,char *buf){
	char chr;
	int i=0;
    for(int i=0;i<20;i++)buf[i]='\0';
	while(1){
		chr = fgetc(fp);
		switch(chr)
		{
			case ' ':
			case ',':
			case '.':
			case '\n':
			case '\r':
			    if(i==0)break;
			    return i;
			case EOF:return 0;
			default:buf[i]=chr;i++;break;
		}
	}
	}

Word *create_node(char *word){
	Word *node=(Word*)malloc(sizeof(Word));
	strcpy(node->name,word);
	node->count=1;
	node->height=1;
	node->left=NULL;
	node->right=NULL;
	return node;
	}
	
int node_height(Word *node){
	int l=node->left!=NULL?node->left->height:0;
	int r=node->right!=NULL?node->right->height:0;
	return l>r?l+1:r+1;
	}
	
int renew(Word *root,Word *node){
	int n;
	if(strcmp(root->name,node->name)>0){
		n=renew(root->left,node)+1;
		root->height=node_height(root);
		return n;
	}else if(strcmp(root->name,node->name)<0){
		n=renew(root->right,node)+1;
		root->height=node_height(root);
		return n;
	}else{
		return node_height(root);
	}
	}

Word *rotate_l(Word *node,Word *parent,Word *root){
	if(parent!=NULL){
		if(strcmp(parent->name,node->name)>0)parent->left=node->right;
		else if(strcmp(parent->name, node->name)<0)parent->right=node->right;
	}else{
		root=node->right;
	}
	node->height=node->height>2?node->height-2:1;
	Word *tmp=node->right->left;
	node->right->left=node;
	node->right=tmp;
	if(node->right!=NULL)renew(root,node->right);
	else renew(root,node);
	return root;
	}

Word *rotate_r(Word *node,Word *parent,Word *root){
	if(parent!=NULL){
		if(strcmp(parent->name,node->name)>0)parent->left=node->left;
		else if(strcmp(parent->name, node->name)<0)parent->right=node->left;
	}else{
		root=node->left;
	}
	node->height=node->height>2?node->height-2:1;
	Word *tmp=node->left->right;
	node->left->right=node;
	node->left=tmp;
	if(node->left!=NULL)renew(root,node->left);
	else renew(root,node);
	return root;
	}

int height_diff(Word *node){
	int l=node->left!=NULL?node->left->height:0;
	int r=node->right!=NULL?node->right->height:0;
	return l-r;
	}

Word *rotate(Word *node,Word *r,Word *p,Word *root){
	if(node==r)return root;
	if(height_diff(r)>1){
		if(height_diff(r->left)<0){
			rotate_l(r->left,r,root);
			root=rotate_r(r,p,root);
		}else{
			root=rotate_r(r,p,root);
		}
	}else if(height_diff(r)<-1){
		if(height_diff(r->right)>0){
			rotate_r(r->right,r,root);
			root=rotate_l(r,p,root);
		}else{
			root=rotate_l(r,p,root);
		}
	}else{
		if(strcmp(r->name,node->name)>0){
			root=rotate(node, r->left, r, root);
		}else{
			root=rotate(node, r->right, r, root);
		}
	}
	return root;
	}
				
Word *add_node(Word *root,char *buf){
	Word *r=root;
	while(r!=NULL)
	{
		if(strcmp(r->name, buf)>0){
			if(r->left!=NULL){
				r=r->left;
			}else{
				r->left=create_node(buf);
				renew(root, r->left);
				return rotate(r->left,root,NULL,root);
			}
		}else if(strcmp(r->name, buf)<0){
			if(r->right!=NULL){
				r=r->right;
			}else{
				r->right=create_node(buf);
				renew(root, r->right);
				return rotate(r->right,root,NULL,root);
			}	
		}else{
			r->count++;
			return root;	
		}
	}
	}
	
void print_nodes(Word *word){
	if(word->left!=NULL){
	    print_nodes(word->left);
		}
	if(word!=NULL){
		printf("%s %d\n",word->name,word->count);
	}
	if(word->right!=NULL){
		print_nodes(word->right);
	}
	}
	
int main(void){
	char buf[20];
	FILE *fp;
	
	fp=fopen("anne.txt", "r");
	if(fp==NULL){
		printf("File read error\n");
		exit(1);
		}
	
	read_word(fp,buf);
	Word *root=(Word*)malloc(sizeof(Word));
	root=create_node(buf);
	while(read_word(fp,buf)>0){
		root=add_node(root,buf);
		}
	print_nodes(root);
	fclose(fp);
	return 0;
	}
