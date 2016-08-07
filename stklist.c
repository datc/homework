// #include <stdlib.h>
// #include <stdio.h>
#include <iostream>
#define SIZE 5
#define true 1
#define false 0
#define bool int

using namespace std;

typedef struct Elem
{
	int v;
	struct Elem * next;
}Elem;

typedef struct Stack{
	Elem * top;
	int len;
};

void init(struct Stack * stk){
	stk->top = NULL;
	stk->len = 0;
}

bool IsFull(struct Stack stk){
	if (stk.len >= SIZE)
	{
		return true;
	}
	return false;
}

bool IsEmpty(struct Stack stk)
{
	return (stk.top == NULL);
}

bool Push(struct Stack *stk, int v){
	if (IsFull(*stk))
	{
		return false;
	}
	Elem * newV = (Elem *)malloc(sizeof(Elem));
	// Elem * newV = new Elem;
	newV->v = v;
	newV->next = stk->top;
	stk->top = newV;
	stk->len ++;
	return true;
}

bool Pop(struct Stack * stk, int * v){
	if (IsEmpty(*stk))
	{
		return false;
	}
	stk->len --;
	*v = stk->top->v;
	stk->top = stk->top->next;
	return true;
}

int main()
{
	struct Stack s;
	int val;
	init(&s);
	Push(&s, 2);
	bool ret = Pop(&s, &val);
	printf("ret = %d\n", ret);
	printf("val = %d", val);
	ret = Pop(&s, &val);
	printf("ret = %d\n", ret);
	printf("val = %d", val);
	return 0;
}


//01234
//
//
