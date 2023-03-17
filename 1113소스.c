#define _CRT_SECURE_NO_WARNINGS			//SLL의 해당 위치의 node 지우기
#include<stdio.h>

struct node
{
	int i;
	struct node* next;
};

struct node* head = 0;

void add(int v)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->next = 0;
	new->i = v;


	if (head == 0)
	{
		head = new;
	}
	else
	{
		struct node* cur = 0;
		cur = head;

		while (cur->next != 0)
		{
			cur = cur->next;
		}
		cur->next = new;
	}
}

void delete2(int v)
{
	struct node* del, *del_prev;

	if (v <= 0)
	{
		return;
	}
	else if (v == 1)
	{
		del = head;
		head = del->next;		//head = head -> next; 도 가능
		free(del);
	}
	else
	{
		del_prev = head;

		for (int i = 2; i < v; i++)
		{
			del_prev = del_prev->next;
			
			if (del_prev->next == 0)
			{
				return;
			}
		}
		 
		del = del_prev->next;
		del_prev->next = del->next;
		free(del);
	}

}

void print(void)
{
	struct node* last = 0;

	last = head;

	while (last != 0)
	{
		printf("%d ", last->i);
		last = last->next;
	}
}

int main()
{
	int num, a, i;

	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d", &a);
		add(a);
	}

	scanf("%d", &a);
	delete2(a);

	print();
}