#define _CRT_SECURE_NO_WARNINGS			// 1번 SLL에 숫자 추가하고 2번 SLL에 숫자 추가
										// 두 SLL에 같은 값이 몇 개인지 출력

#include<stdio.h>

struct node1
{
	int i;
	struct node1* next;
};

struct node1* head1 = 0;

struct node2
{
	int i;
	struct node2* next;
};

struct node2* head2 = 0;

void addtoSLL1(int v)
{
	struct node1* new = (struct node1*)malloc(sizeof(struct node1));

	new->i = v;
	new->next = 0;

	if (head1 == 0)
	{
		head1 = new;
	}
	else
	{
		struct node1* last;
		last = head1;

		while (last->next != 0)
		{
			last = last->next;
		}
		last->next = new;
	}

}

void addtoSLL2(int v)
{
	struct node2* new = (struct node2*)malloc(sizeof(struct node2));

	new->i = v;
	new->next = 0;

	if (head2 == 0)
	{
		head2 = new;
	}
	else
	{
		struct node2* last;
		last = head2;

		while (last->next != 0)
		{
			last = last->next;
		}
		last->next = new;
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
		
		if (cur1->next == 0)
		{
			break;
		}

		n++;
		cur1 = cur1->next;
	}

	a[n + 1] = 0;

	return a;
}

int save2(void)
{

	struct node2* cur2 = 0;
	cur2 = head2;

	int b[100], n = 0, k;

	while (1)
	{
		b[n] = cur2->i;

		if (cur2 ->next == 0)
		{
			break;
		}

		n++;
		cur2 = cur2->next;

	}

	b[n + 1] = 0;

	return b;
}


void numofsame(int* a, int* b)
{
	int cnt = 0;

	for (int i = 0; i < 100; i++)
	{
		if (a[i] == 0)
		{
			break;
		}

		for (int k = 0; k < 100; k++)
		{
			if (b[k] == 0)
			{
				break;
			}
			else if(a[i] == b[k])
			{
				cnt++;
			}
			

		}



	}


	printf("%d", cnt);
}

int main()
{
	int a, i, num;
	int* ap, * bp;

	scanf("%d", &num);			// 1번 SLL
	for (i = 0; i < num; i++)
	{
		scanf("%d", &a);
		addtoSLL1(a);
	}

///////////////////////////////////////
	
	scanf("%d", &num);			// 2번 SLL
	for (i = 0; i < num; i++)
	{
		scanf("%d", &a);
		addtoSLL2(a);
	}



	struct node1* cur1 = 0;
	cur1 = head1;

	int aaa[100], n1 = 0;

	while (1)
	{
		aaa[n1] = cur1->i;

		if (cur1->next == 0)
		{
			break;
		}

		n1++;
		cur1 = cur1->next;
	}

	aaa[n1 + 1] = 0;

	/////////////////////////////
	
	struct node2* cur2 = 0;
	cur2 = head2;

	int bbb[100], n2 = 0;

	while (1)
	{
		bbb[n2] = cur2->i;

		if (cur2->next == 0)
		{
			break;
		}

		n2++;
		cur2 = cur2->next;

	}

	bbb[n2 + 1] = 0;



	ap = aaa;
	bp = bbb;

	numofsame(ap, bp);


}