#include<stdio.h>
#include<stdlib.h>
#define ll long long

const ll max=100000;
ll top=-1;


void push(ll stack[],ll x)
{
	if(top==max-1)
		printf("\nStack Full\n");
	else
	{
		top++;
		stack[top]=x;
	}
}

void pop(ll stack[])
{
	if(top<0)
		printf("\nStack Empty\n");
	else
		top--;
}

void display(ll stack[])
{
	if(top<0)
		printf("\nEmpty\n");
	else
	{
		for(ll x=top;x>=0;x--)
			printf("%lld ",stack[x]);
		printf("\n");
	}
}

void delete_middle(ll stack[])
{
	if(top<0)
		printf("\nEmpty\n");
	else
	{
		ll x=(top)/2;
		while(x<top){
			stack[x]=stack[x+1];
			x++;
		}
		top--;
	}
}

void insert_middle(ll stack[],ll num)
{
	if(top==max-1)
		printf("\nStack Full\n");
	else if(top<0)
		stack[++top]=num;
	else
	{
		top++;
		for(ll x=top-1;x>=(top)/2;x--)
		{
			stack[x+1]=stack[x];
		}
		stack[top/2]=num;
	}
}

int main()
{
	ll stack[max];
	printf("\nInitially stack: \t");
	display(stack);
	while(1)
	{
		printf("Choose: 1-input at middle 2-delete at middle 3:exit\t");
		int ch;
		scanf("%d",&ch);
		if(ch==3)
			break;
		if(ch==1)
		{
			ll x;
			scanf("%lld",&x);
			insert_middle(stack,x);
			printf("\nAfter middle insertion stack:\n");
			display(stack);
		}
		else if(ch==2){
			delete_middle(stack);
			printf("\nAfter middle deletion stack:\n");
			display(stack);
		}
		else
			printf("\nWrong input\n");
	}
	return 0;
}
