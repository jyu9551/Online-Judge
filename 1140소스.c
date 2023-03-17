#define _CRT_SECURE_NO_WARNINGS   

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Qsize 7
#define true 1
#define false 0

char* queue[Qsize];
int front = 0, rear = 0;

int isempty()
{
	if (front == rear)
	{
		return true;
	}
	return false;
}
int isfull()
{
	if (front == (rear + 1) % Qsize)
	{
		return true;
	}
	return false;
}

void enqueue(int v)
{
	if (isfull() == 1)
	{
		return;
	}
	else
	{
		if (v == 100)
		{
			queue[1] = sum(rear);

			front = 0;
			rear = 1;
		}
		else
		{
			rear++;
			rear = rear % Qsize;
			queue[rear] = v;
		}
	}
}
int dequeue()
{
	if (isempty() == 1)
	{
		return -999;
	}
	else
	{
		front++;
		front = front % Qsize;
		return queue[front];
	}
}

int sum(int n)
{
	int i, sum = 0;

	for (i = 1; i <= n; i++)
	{
		sum = sum + queue[i];
	}
	return sum;
}

int main(void)
{
	int num, i, v;

	scanf("%d", &num);
	
	for (i = 0; i < num; i++)
	{

		scanf("%d", &v);
		enqueue(v);
	}
	for (i = 0; i < num; i++)
	{

		int a = dequeue();
		if (a != -999)
		{
			printf("%d ", a);
		}
	}

}