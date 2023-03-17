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


void sequential()
{
	struct node* cur = head;
	struct node* temp = head;
	int tmp;

	while (cur != 0)
	{
		temp = head;
		while (temp != 0)
		{
			if (cur->i < temp->i)
			{
				tmp = cur->i;
				cur->i = temp->i;
				temp->i = tmp;
			}
			temp = temp->next;
		}
		cur = cur->next;
	}
}

void count()
{
	struct node* cur = head;
	int cnt = 1;

	while (cur != 0)
	{
		while (cur->i == cur->next->i)
		{	

			cnt++;
			cur = cur->next;

			if (cur->next == 0)
			{
				break;
			}
		}
		printf("%d %d ", cur->i, cnt);
		cnt = 1;
		cur = cur->next;
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

	sequential();

	count();
}