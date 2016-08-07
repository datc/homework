#include <stdlib.h>
#include <stdio.h>
#define SIZE 5
#define true 1
#define false 0
#define bool int


typedef struct Stack{
	int * base;
	int *top;
};

void init(struct Stack * stk){
	// stk->base = new int[SIZE];
	stk->base = (int*)malloc((SIZE + 1) * sizeof(int));
	stk->top = stk->base;
}

bool IsFull(struct Stack stk){
	if (stk.top - stk.base >= SIZE + 1)
	{
		return true;
	}
	return false;
}

bool IsEmpty(struct Stack stk)
{
	return (stk.top == stk.base);
}

bool Push(struct Stack *stk, int v){
	if (IsFull(*stk))
	{
		return false;
	}
	*(stk->top) = v;
	stk->top ++;
	return true;
}

bool Pop(struct Stack * stk, int * v){
	if (IsEmpty(*stk))
	{
		return false;
	}
	stk->top --;
	*v = *(stk->top);
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
