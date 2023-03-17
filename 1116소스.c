#define _CRT_SECURE_NO_WARNINGS			// SLL에 숫자 추가하고 삽입함수 추가
										// 단, 삽입함수이지만 insert(a,b)에서
										// a 앞에 b를 추가한다.

	
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

void insert2(int v, int w)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->i = w;

	struct node* cur = head;

	while (cur->next != 0)
	{
		if (cur->next->i == v)
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

	new->next = 0;
	cur->next = new;
	
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

	insert2(m, n);

	printSLL();
}