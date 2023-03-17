#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>		//addtoDLL

struct node
{
	int i;
	struct node* next;
	struct node* prev;
};

struct node* head = 0;

void add(int v)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));

	new->next = 0;
	new->prev = 0;
	new->i = v;

	if (head == 0)
	{
		head = new;
		return;
	}
	else
	{
		struct node* cur = head;

		while (cur->next != 0)
		{
			cur = cur->next;
		}
		new->prev = cur;
		cur->next = new;
	}
}


void print()
{
	struct node* cur = head;

	if (head == 0)
	{
		printf("-999");
	}
	else
	{
		while (cur != 0)
		{
			printf("%d ", cur->i);
			cur = cur->next;
		}
	}
}

int main()
{
	int a, num, i;

	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d", &a);
		add(a);
	}

	print();

}