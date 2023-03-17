#define _CRT_SECURE_NO_WARNINGS			
#include<stdio.h>		//add to DLL -> insert DLL -> reverse print

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

void insert(int v, int w)
{
	struct node* cur = head;
	struct node* new = (struct node*)malloc(sizeof(struct node));

	new->i = w;
	new->next = 0;
	new->prev = 0;

	while (cur != 0)
	{
		if (cur->i == v)
		{
			if (cur->next == 0)
			{
				cur->next = new;
				new->prev = cur;
				return;
			}
			else
			{
				new->next = cur->next;
				new->prev = cur;
				cur->next->prev = new;
				cur->next = new;
				return;
			}
		}
		else
		{
			cur = cur->next;
		}

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


void invprint()
{
	struct node* cur = head;
	int a[100];
	int n = 0;

	while (cur != 0)
	{
		a[n] = cur->i;
		n++;
		cur = cur->next;
	}

	for (int i = n-1; i >= 0; i--)
	{
		printf("%d ", a[i]);
	}
	return;
}

int main()
{
	int a, b, num, i;

	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d", &a);
		add(a);
	}

	scanf("%d %d", &a, &b);

	insert(a, b);

	invprint();

}