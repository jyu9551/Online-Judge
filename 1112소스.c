#if 0	//C++				//SLL�� �ش� ������ node �����
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

void deleteSLL(int b)
{
	struct node *del = 0, *del_prev = 0;

	if (head->i == b)
	{
		del = head;
		head = del->next;
		free(del);
	}
	else
	{

		del_prev = head;
		del = del_prev->next;

		while (del != 0)
		{
			if (del->i == b)
			{
				del_prev->next = del->next;
				free(del);
			}
			else
			{
				del_prev = del_prev->next;
				del = del->next;
			}
		}
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

	scanf("%d", &a);
	deleteSLL(a);

	printSLL();

	return 0;
}
#endif

#if 1		//C
#define _CRT_SECURE_NO_WARNINGS
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

void delete(int v)
{
	struct node* del, * del_prev;

	if (head->i == v)
	{
		del = head;
		free(del);

	}
	else
	{
		del_prev = head;

		while (del_prev->next != 0)
		{
			if (del_prev->next->i == v)
			{
				del = del_prev->next;
				del_prev->next = del->next;
				free(del);
			}
			else
			{
				del_prev = del_prev->next;
			}
		}

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
	delete(a);

	print();
}
#endif // 1
