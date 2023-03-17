#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#define stack_max 100
#define true 1
#define false 0

int stack[stack_max];
int top = -1;

int isempty()
{
	if (top == -1)
	{
		return true;
	}
	return false;
}
int isfull()
{
	if (top == stack_max - 1)
	{
		return true;
	}
	return false;
}


void push(int v)
{
	if (isfull() == true)
	{
		return false;
	}
	else
	{
		if (v != 100)
		{
			top++;
			stack[top] = v;
		}
		else
		{
			top++;
			int a = sum(top);
			top = 0;
			stack[top] = a;
		}
	}
}
int pop(void)
{
	if (isempty() == true)
	{
		return -999;
	}
	else
	{
		int v = stack[top];
		top--;
		return v;
	}
}

int sum(int top)
{
	int i,sum = 0;

	for (i = 0; i <= top;i++)
	{
		sum = sum + pop();
	}
	return sum;
}


int main()
{
	int num, i, a;

	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d", &a);
		push(a);
	}
	for (i = 0; i < num; i++)
	{
		int v = pop();

		if (v != -999)
		{
			printf("%d ", v);
		}
	}

}