#define _CRT_SECURE_NO_WARNINGS   

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Qsize 5
#define true 1
#define false 0

char *queue[Qsize];
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
		rear++;
		rear = rear % Qsize;
		queue[rear] = v;
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
		if (a == -999)
		{
			break;
		}
		printf("%d ", a);
	}

}