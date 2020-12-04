#include<stdio.h>
#include<stdlib.h>
#define ll long long

#define Max 1e5
struct stack{
	ll front,rear,q1[100000],q2[100000];
}Stack;

void push(ll num)
{
	if(Stack.rear==Max-1)
	{
		printf("\nStack full\n");
		return;
	}
	if(Stack.front==-1)
		Stack.front=0;
	Stack.q1[++(Stack.rear)]=num;
}

void pop()
{
	if(Stack.front==-1)
	{
		printf("\nStack Empty\n");
		return;
	}
	else if (Stack.front==Stack.rear)
	{
		Stack.front=Stack.rear=-1;
		return;
	}
	ll i=-1;
	while(Stack.front<Stack.rear)
	{
		Stack.q2[++i]=Stack.q1[Stack.front++];
	}
	Stack.front=0;
	Stack.rear=-1;
	for(ll j=0;j<=i;j++)
	{
		Stack.q1[++(Stack.rear)]=Stack.q2[j];
	}
}

void display()
{
	if(Stack.front==-1)
	{
		printf("\nStack Empty\n");
		return;
	}
	for(ll i=Stack.rear;i>=Stack.front;i--)
		printf("%lld ",Stack.q1[i]);

}
void top()
{
	if(Stack.front==-1)
	{
		printf("\nStack Empty\n");
		return;
	}
	printf("\n%lld\n",Stack.q1[Stack.rear]);
	
}


int main(){
	Stack.front=Stack.rear=-1;
	while(1)
	{
		printf("\nChoose: 1-input in stack 2-delete from stack 3-top of stack 4:exit\t");
		ll ch;
		scanf("%lld",&ch);
		if(ch==4)
			break;
		if(ch==1)
		{
			ll x;
			scanf("%lld",&x);
			push(x);
			printf("\nAfter insertion stack:\n");
			display();
		}
		else if(ch==2){
			pop();
			printf("\nAfter deletion stack:\n");
			display();
		}
		else if(ch==3){
			printf("\ntop of stack:\n");
			top();
		}
		else 
			printf("\nWrong input\n");
	}
	return 0;

}
