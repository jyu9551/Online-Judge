#define _CRT_SECURE_NO_WARNINGS   
#include<stdio.h>
#define stack_max 5
#define true 1
#define false 0

int stack[stack_max];
int top = -1;

int isempty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}
int isfull()
{
    if (top == stack_max - 1)
    {
        return true;
    }
    return false;
}


void push(int v)
{
    if (isfull() == true)
    {
        return;
    }
    else
    {
        top++;
        stack[top] = v;
    }
}
int pop(void)
{
    if (isempty() == true)
    {
        return -999;
    }
    else
    {
        int v = stack[top];
        top--;
        return v;
    }
}


int main()
{
    int num, i, a;

    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        scanf("%d", &a);
        push(a);
    }
    for (i = 0; i < num; i++)
    {
        int v = pop();
        if (v != -999)
        {
            printf("%d ", v);
        }
    }

}