#include<stdio.h>
#include<stdlib.h>
#define ll long long

const ll max=100000;
ll top1=-1,top2=max;;


void push_st1(ll stack[],ll x)
{
	if(top1==top2-1)
		printf("\nStack Full\n");
	else
	{
		top1++;
		stack[top1]=x;
	}
}

void pop_st1(ll stack[])
{
	if(top1<0)
		printf("\nStack Empty\n");
	else
		top1--;
}

void push_st2(ll stack[],ll x)
{
	if(top1==top2-1)
		printf("\nStack Full\n");
	else
	{
		top2--;
		stack[top2]=x;
	}
}

void pop_st2(ll stack[])
{
	if(top2==max)
		printf("\nStack Empty\n");
	else
		top2++;
}

void display(ll stack[])
{
	printf("\nstack1 ");
	for(ll x=top1;x>=0;x--)
		printf("%lld ",stack[x]);
	printf("\nstack2 ");
	for(ll x=top2;x<max;x++)
		printf("%lld ",stack[x]);
}



int main()
{
	ll stack[max];
	while(1)
	{
		printf("\nChoose: 1-input stack1 2-input stack2 3:delete stack1 4:delete stack2 5:exit\t");
		int ch;
		scanf("%d",&ch);
		if(ch==5)
			break;
		if(ch==1)
		{
			ll x;
			scanf("%lld",&x);
			push_st1(stack,x);
			printf("\nAfter insertion stack1:\n");
			display(stack);
		}
		else if(ch==2)
		{
			ll x;
			scanf("%lld",&x);
			push_st2(stack,x);
			printf("\nAfter insertion stack2:\n");
			display(stack);
		}
		else if(ch==3){
			pop_st1(stack);
			printf("\nAfter deletion stack1:\n");
			display(stack);
		}
		else if(ch==4){
			pop_st2(stack);
			printf("\nAfter deletion stack2:\n");
			display(stack);
		}
		else 
			printf("\nWrong input\n");
	}
	return 0;
}
