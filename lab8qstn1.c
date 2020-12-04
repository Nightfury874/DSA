#include<stdio.h>
#include<stdlib.h>
#define ll long long

#define Max 1e5
ll front,rear,queue[100000];

void enqueue(ll num)
{
	if(rear==Max-1){
		printf("\nQueue full\n");
		return;
	}
	if(front==-1)
		front++;
	rear++;
	queue[rear]=num;
}

void deque()
{
	if(front==-1)
	{
		printf("\nQueue Empty\n");
		return;
	}
	if(front==rear)
		front=rear=-1;
	else
		front++;
}

void insert_middle(ll num)
{
	if(rear==Max-1){
		printf("\nQueue full\n");
		return;
	}
	if(front==-1)
		queue[++front]=num,rear++;
	else{
	ll mid=(rear+front)/2;
	ll pos=rear++;
	while(pos>mid)
	{
		queue[pos+1]=queue[pos];
		pos--;
	}
	queue[pos+1]=num;
	}
}

void delete_middle()
{
	if(front==-1)
	{
		printf("\nQueue Empty\n");
		return;
	}
	ll mid=(front+rear+1)/2;
	while(mid>front)
	{
		queue[mid]=queue[mid-1];
		mid--;
	}
	if(front==rear)
		front=rear=-1;
	else
		front++;
}

void display(){
	if(front==-1)
	{
		printf("\nQueue Empty\n");
		return;
	}
	else
	{
		for(ll i=front;i<=rear;i++)
			printf("%lld ",queue[i] );
	}

}

int main(){
	front=rear=-1;
	enqueue(1);
	enqueue(2);
	while(1)
	{
		printf("\nChoose: 1-input at middle 2-delete at middle 3:exit\t");
		ll ch;
		scanf("%lld",&ch);
		if(ch==3)
			break;
		if(ch==1)
		{
			ll x;
			scanf("%lld",&x);
			insert_middle(x);
			printf("\nAfter middle insertion queue:\n");
			display();
		}
		else if(ch==2){
			delete_middle();
			printf("\nAfter middle deletion queue:\n");
			display();
		}
		else
			printf("\nWrong input\n");
	}
	return 0;
}
