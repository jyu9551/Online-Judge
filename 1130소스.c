#if 0
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

void forbackprint(int v)
{
	struct node* cur = head;
	struct node* threenine = (struct node*)malloc(sizeof(struct node));

	threenine->i = -999;
	threenine->next = 0;
	threenine->prev = 0;

	while (cur != 0)
	{
		if (cur->i == v)
		{
			if (cur -> prev == 0)
			{
				threenine->next = cur;
				cur->prev = threenine;
			}
			
			if (cur->next == 0)
			{
				threenine->prev = cur;
				cur->next = threenine;
			}

			printf("%d %d", cur->prev->i, cur->next->i);
			return;
		}
		else
		{
			cur = cur->next;
		}

	}
    printf("-999");

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

	scanf("%d", &b);

	forbackprint(b);
}
#endif


#if 1
#define _CRT_SECURE_NO_WARNINGS			
#include<stdio.h>

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

void printapdui(int v)
{
	struct node* cur = head;

	while (cur != 0)
	{
		if (cur->i == v)
		{
			if (cur->prev == 0)
			{
				printf("-999 ");
			}
			else
			{
				printf("%d ", cur->prev->i);
			}
			if (cur->next == 0)
			{
				printf("-999 ");
			}
			else
			{
				printf("%d", cur->next->i);
			}
			return;
		}
		else
		{
			cur = cur->next;
		}
	}
	printf("-999");
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

	scanf("%d", &b);

	printapdui(b);

}


#endif // 1
