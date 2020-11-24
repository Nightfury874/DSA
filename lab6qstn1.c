#include<stdio.h>
#include<stdlib.h>

struct linkedList{
	int data;
	struct linkedList* next,*prev;
};
struct linkedList* head=NULL;

void insert_at_last(int value){
	struct linkedList* temp=(struct linkedList*)malloc(sizeof(struct linkedList));
	temp->data = value;
	temp->next = temp->prev=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else 
	{
		struct linkedList *itr=head;
		while(itr->next!= NULL)
		{
			itr = itr->next;
		}
		itr->next=temp;
		temp->prev=itr;
	}
}

void insert_at_front(int value){
	struct linkedList* temp=(struct linkedList*)malloc(sizeof(struct linkedList));
	temp->data = value;
	temp->next = temp->prev=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else 
	{
		temp->next=head;
		head=temp;
	}
}

void insert_after_node(int value1,int value2){
	struct linkedList* temp=(struct linkedList*)malloc(sizeof(struct linkedList));
	temp->data = value1;
	temp->next = temp->prev=NULL;
	struct linkedList *itr=head;
	while(itr!= NULL && itr->data!=value2 )
	{
		itr = itr->next;
	}
	if(itr)
	{
		temp->next=itr->next;
		if(temp->next)
			(temp->next)->prev=temp;
		temp->prev=itr;
		itr->next=temp;
	}
	else
	{
		printf("\n%d not found\n",value2);
	}
		
}

void insert_before_node(int value1,int value2){
	struct linkedList* temp=(struct linkedList*)malloc(sizeof(struct linkedList));
	temp->data = value1;
	temp->next = temp->prev=NULL;
	struct linkedList *itr1=head,*itr2=head;
	while(itr2!= NULL && itr2->data!=value2 )
	{
		itr1=itr2;
		itr2 = itr2->next;
	}
	if(itr2)
	{

		temp->next=itr2;
		itr2->prev=temp;
		temp->prev=itr1;
		if(itr1)
			itr1->next=temp;
	}
	else
	{
		printf("\n%d not found\n",value2);
	}
		
}

void displayList()
{
	if(head==NULL)
		printf("\nList is Empty\n");
	else{
		struct linkedList *itr=head;		
		while(itr!=NULL)
		{
			printf("%d\t",itr->data);
			itr=itr->next;
		}
	}
}



int main(){
	do{
		printf("\nEnter 1-insert at front\t2-insert at last\t3-insert after node\t4-insert before node\t5-exit\n");
		int ch,value1,value2;
		scanf("%d",&ch);
		if(ch==5)
			break;
		switch(ch)
		{
			case 1:scanf("%d",&value1);
				insert_at_front(value1);
				break;
			case 2:scanf("%d",&value1);
				insert_at_last(value1);
				break;
			case 3:scanf("%d",&value1);
				printf("\nenter node value\t");
				scanf("%d",&value2);
				insert_after_node(value1,value2);
				break;
			case 4:scanf("%d",&value1);
				printf("\nenter node value\t");
				scanf("%d",&value2);
				insert_before_node(value1,value2);		

		}
		printf("\nAfter insertion\n");
		displayList();
	}while(1);
	return 0;
}
