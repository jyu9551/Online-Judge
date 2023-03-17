#if 1	//C++		//SLL�� ���� ������ �߰��ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct node {
	int i;
	struct node* next;		//�ڱ����� ����ü
};
struct node* head = 0;		//head�� �ʱⰪ = NULL

void addtoSLL(int v)		//v���� ���� node�� �߰�
{
	struct node* new_one = (struct node*)malloc(sizeof(struct node));	//���ο� node�� ���� ���� new_one ����
	new_one->i = v;		//node data�� v ����
	new_one->next = 0;		//new_one�� ���� node�� NULL

	if (head == 0)		//SLL�� �ƹ��͵� ���� ���
	{
		head = new_one;
		//	return;
	}
	else               //SLL�� ���𰡰� �ִ� ���
	{
		struct node* last;
		last = head;

		while (last->next != 0)		//last�� NULL�� ��ġ�ϱ� ������
		{
			last = last->next;
		}
		last->next = new_one;			//last �ڿ� new_one "add"
	//	return;
	}

}

void printSLL()					//added SLL�� printf �ϴ� printSLL()
{
	struct node* cur = 0;
	cur = head;

	while (cur != 0)
	{
		printf("%d ", cur->i);
		cur = cur->next;
	}
}

int main()
{
	int num, i, a;

	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d", &a);
		addtoSLL(a);
	}
	printSLL();

	return 0;
}
#endif

#if 0		//C
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

int save1(void)
{
	struct node1* cur1 = 0;
	cur1 = head1;

	int a[100], n = 0, k;

	while (1)
	{
		a[n] = cur1->i;
		n++;
		if (cur1 == 0)
		{
			break;
		}
		cur1 = cur1->next;
	}

	for (int i = 0; i < 100; i++)
	{
		if (a[i] == 0)
		{
			break;
		}
		printf("%d/", a[i]);
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
	printSLL();
}
#endif // 1
