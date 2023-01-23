#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *start = NULL,*newnode,*ptr,*pptr;

int find_no_nodes(){
	int count = 0;
	if(start == NULL){
		
	}
	else{
		ptr = start;
		while(ptr!=NULL){
			ptr= ptr->next;
			count++;
		}
	}
	return count;
}


void print_no_nodes(){
	int count = 0;
	if(start == NULL){
	
	}
	else{
		ptr = start;
		while(ptr!=NULL){
			count++;
			ptr= ptr->next;
		}
	}
	printf("\nNo of nodes are %d\n",count);
}


void create(){
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data : ");
	scanf("%d",&newnode->data);
	if(start == NULL){
		newnode->prev = NULL;
		start = newnode;
	}
	else{
		ptr = start;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		newnode->prev=ptr;
		ptr->next=newnode;
	}
	newnode->next=NULL;
}

void display(){
	printf("[ start ] <==> ");
	if(start == NULL){
	}
	else{
		ptr = start;
		while(ptr!=NULL){
			printf("[ %d ] <==> ",ptr->data);
			ptr = ptr->next;
		}
	}
	printf("[ null ]\n");
}

void inser_begin(){
	if(start == NULL){
		create();
	}
	else{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter the data : ");
		scanf("%d",&newnode->data);
		newnode->next=start;
		start->prev=newnode;
		start=newnode;
	}
}

void insert_end(){
	if(start == NULL){
		printf("\nInserction at end is not possible \n");
	}
	else{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter the data : ");
		scanf("%d",&newnode->data);
		ptr = start;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		ptr->next=newnode;
		newnode->prev=ptr;
		newnode->next=NULL;
	}
}

void main(void){
	int ch;
	while(1){
		printf("\n1-create\n2-display\n3-insert begin\n4-print no of nodes\n5-insert end\n0-exit\n");
		printf("Enter the choise :");
		scanf("%d",&ch);
		switch(ch){
			case 1:create();
			break;
			case 2:display();
			break;
			case 3:inser_begin();
			break;
			case 4:print_no_nodes();
			break;
			case 5:insert_end();
			break;
			case 0:exit(1);
			break;
		}
	}
}
