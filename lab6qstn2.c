#include<stdio.h>
#include<stdlib.h>

struct linkedList{
	int data;
	struct linkedList* next,*prev;
};
struct linkedList* head=NULL;

void insertNode(int value){
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

void deleteNode(int value)
{
	if(head==NULL)
		printf("List is Empty\n");
	else if(head->data==value)
	{
		struct linkedList *temp = head;
		head=head->next;
		if(head)
			head->prev=NULL;
		free(temp);
	}
	else
	{
		struct linkedList *itr1= head,*itr2=head;
		while(itr2->data!=value && itr2->next!=NULL)
		{
			itr1=itr2;
			itr2=itr2->next;
		}
		if(itr2->data==value)
		{
			itr1->next=itr2->next;
			if(itr2->next)
				(itr2->next)->prev=itr1;
			free(itr2);
		}
		else
			printf("\nposition not found\n");
		
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
	insertNode(1);
	insertNode(2);
	insertNode(3);
	insertNode(4);
	insertNode(5);
	printf("\nInitially doubly liked list is\n");
	displayList();
	do{
		printf("\nEnter value to delete or 0 to exit\n");
		int ch;
		scanf("%d",&ch);
		if(ch)
		{
			deleteNode(ch);
			printf("\nAfter deletion\n");
			displayList();
		}
		else
			break;
	}while(1);
	return 0;
}
