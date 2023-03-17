#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>					//주어진 숫자들로 DLL을 구성하고, 입력된 숫자와 동일한 node 모두 삭제

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
	struct node* cur = head;

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

void deleteDLL(int v)
{
	struct node* cur = head;

	while (cur != 0)
	{		
		if (cur->i == v)
		{
			if (cur == head)
			{
				head = head->next;

				if (head != 0)
				{
					head->prev = 0;
				}
				free(cur);
				return;
			}
			else
			{
				cur->prev->next = cur->next;
				if (cur->next != 0)
				{
					cur->next->prev = cur->prev;
				}
				free(cur);
				return;
			}
		}
		else
		{
			cur = cur->next;
		}

	}
}

int main()
{
	int a = 0, num = 0, i;

	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d", &a);
		add(a);
	}

	int d = 0;

	scanf("%d", &d);

	for (i = 0; i < num; i++)
	{
		deleteDLL(d);
	}
	print();

}