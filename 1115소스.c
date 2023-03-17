#define _CRT_SECURE_NO_WARNINGS			//SLL에 숫자 추가하고 삽입함수 추가
#include<stdio.h>

struct node
{
	int i;
	struct node* next;
};

struct node* head = 0;

void addtoSLL(int v)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));

	new->i = v;
	new->next = 0;

	if (head == 0)
	{
		head = new;
	}
	else
	{
		struct node* last;
		last = head;

		while (last->next != 0)
		{
			last = last->next;
		}
		last->next = new;
	}

}

void insert(int v, int w)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->i = w;

	struct node* cur = 0;

	cur = head;

	while (cur != 0)
	{
		if (cur->i == v)
		{
			new->next = cur->next;
			cur->next = new;
			return;
		}
		else
		{
			cur = cur->next;
		}
	}
	cur = head;
	new->next = cur;
	head = new;
	return;
}

void printSLL()
{
	struct node* last;

	last = head;
	while (last != 0)
	{
		printf("%d ", last->i);
		last = last->next;
	}
}

int main()
{
	int a, i, num;

	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d", &a);
		addtoSLL(a);
	}

	int m, n;
	scanf("%d %d", &m, &n);

	insert(m, n);

	printSLL();
}