#if 1	//C++		//SLL에 숫자 데이터 추가하기
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct node {
	int i;
	struct node* next;		//자기참조 구조체
};
struct node* head = 0;		//head의 초기값 = NULL

void addtoSLL(int v)		//v값을 가진 node를 추가
{
	struct node* new_one = (struct node*)malloc(sizeof(struct node));	//새로운 node가 들어올 공간 new_one 생성
	new_one->i = v;		//node data에 v 저장
	new_one->next = 0;		//new_one의 다음 node는 NULL

	if (head == 0)		//SLL에 아무것도 없는 경우
	{
		head = new_one;
		//	return;
	}
	else               //SLL에 무언가가 있는 경우
	{
		struct node* last;
		last = head;

		while (last->next != 0)		//last가 NULL에 위치하기 전까지
		{
			last = last->next;
		}
		last->next = new_one;			//last 뒤에 new_one "add"
	//	return;
	}

}

void printSLL()					//added SLL을 printf 하는 printSLL()
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
