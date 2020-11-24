#include<stdio.h>
#include<stdlib.h>

struct linkedList{
	int data;
	struct linkedList* next;
};
struct linkedList* head=NULL;

void insertNode(int value){
	struct linkedList* temp=(struct linkedList*)malloc(sizeof(struct linkedList));
	temp->data = value;
	if(head)
	{
		temp->next=head;
		struct linkedList *itr=head;
		while(itr->next!=head)
			itr=itr->next;
		itr->next=temp;
	}
	else
	{
		temp->next=temp;
		head=temp;
	}	
}

void deleteNode(int value)
{
	if(head==NULL)
		printf("List is Empty\n");
	else if(head->data==value)
	{
		if(head->next==head)
		{
			free(head);
			head=NULL;
		}
		else{
			struct linkedList *temp = head,*itr=head;
		while(itr->next!=head)
			itr=itr->next;
		itr->next=head=head->next;
		free(temp);	
		}
		
	}
	else
	{
		struct linkedList *itr1= head,*itr2=head;
		int flag=1;
		while((itr2->data!=value && itr2->next!=head)||flag)
		{
			flag=0;
			itr1=itr2;
			itr2=itr2->next;
		}
		if(itr2->data==value)
		{
			itr1->next=itr2->next;
			free(itr2);
		}
		else
			printf("\nvalue not found\n");
		
	}
}

void displayList()
{
	if(head==NULL)
		printf("\nList is Empty\n");
	else{
		struct linkedList *itr=head;
		int flag=1;		
		while(flag || itr!=head )
		{
			flag=0;
			printf("%d\t",itr->data);
			itr=itr->next;
		}
	}
}


int main(){
	do{
		printf("\nchoose your option:\n1- insertion\n2-deletion\n3-display\n4-exit\n");
		int ch,data,pos;
		scanf("%d",&ch);
		if(ch==4)
			break;
		switch(ch)
		{
			case 1:	scanf("%d",&data);
					insertNode(data);
					break;
			case 2: scanf("%d",&data);
					deleteNode(data);
					break;
			case 3:displayList();break;
		}
	}while(1);
	return 0;
}
