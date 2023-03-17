#define _CRT_SECURE_NO_WARNINGS			//SLL에 숫자 추가하여 역순 출력하기
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

void inv_print(void)
{
	struct node* last = 0;
	last = head;

	int a[100], n = 0, k;

	while (1)
	{
		a[n] = last->i;
		last = last->next;
		n++;

		if (last == 0)
		{
			break;
		}
	}

	for (k = n - 1; k >= 0; k--)
	{
		printf("%d ", a[k]);
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

	inv_print();
}