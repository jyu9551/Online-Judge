#define _CRT_SECURE_NO_WARNINGS   

#include<stdio.h>

struct node
{
	int i;
	struct node* left;
	struct node* right;
};
struct node* root = 0;

void add(int v)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->i = v;
	new->left = 0;
	new->right = 0;

	struct node* cur = root;

	if (root == 0)
	{
		root = new;
		return;
	}

	while (1)
	{
		if (cur->i > new->i)
		{
			if (cur->left == 0)
			{
				cur->left = new;
				return;
			}
			else
			{
				cur = cur->left;
			}
		}
		else
		{
			if (cur->right == 0)
			{
				cur->right = new;
				return;
			}
			else
			{
				cur = cur->right;
			}
		}
	}

}

struct node* findleast(struct node* cur)
{
	struct node* least = cur;
	while (cur->left != 0)
	{
		cur = cur->left;
	}
	return cur;
}

void delete(struct node* cur, int v)
{
	if (cur == 0)
	{
		return;
	}

		if (v == cur->i)		//found
		{
			if (cur->left == 0 && cur->right == 0)
			{
				free(cur);
				return;
			}
			else if (cur->left == 0)
			{
				struct node* temp = cur->right;
				free(cur);
				cur = temp;
				return;
			}
			else if (cur->right == 0)
			{
				struct node* temp = cur->left;
				free(cur);
				cur = temp;
				return;
			}
			else		// 두 자식 모두 가진 경우 :  
			{
				struct node* min = findleast(cur->right);
			//	free(cur);
			//	cur = min;
			//	return;

				cur->i = min->i;
				free(cur->left);
				free(cur->right);
			}
		}
		else if (v < cur->i)
		{
			cur = cur->left;
			delete(cur, v);
		}
		else if (v > cur->i)
		{
			cur = cur->right;
			delete(cur, v);
		}
	
	return;
}

int main()
{
	int v,num,i;

	struct node* cur = 0;

	while (1)
	{
		scanf("%d", &v);

		if (v == 999)
		{
			break;
		}
		add(v);
	}

	cur = root;

	while (1)
	{
		scanf("%d", &v);

		if (v == 2)
		{
			printf("%d",cur->i);
			return;
		}
		else if (v == 0)
		{
			if (cur->left == 0)
			{
				printf("-999");
				return;
			}
			else
			{
				cur = cur->left;
			}
		}
		else
		{
			if (cur->right == 0)
			{
				printf("-999");
				return;
			}
			else
			{
				cur = cur->right;
			}
		}
	}


//	delete(root,20);

//	printf("%d %d %d %d", root->i, root->left->i, root->right->i, root->left->left->i);

}