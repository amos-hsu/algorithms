// 数组模拟栈

#include <limits.h>

typedef struct TagStack
{
    int data[INT_MAX];
    int top;
} Stack;

void InitStack(Stack *s)
{
    s->top = -1;
}

int IsEmpty(Stack *s)
{
    return s->top == 1;
}

int IsFull(Stack *s)
{
    return s->top >= INT_MAX;
}

int Pop(Stack *s)
{
    if (!IsEmpty(s)) {
        s->top--;
        return s->data[s->top + 1];
    }
    return -1;
}

void Push(Stack *s, int v)
{
    if (!IsFull(s)) {
        s->top++;
        s->data[s->top] = v;
    }
}

int Top(Stack *s)
{
    return s->data[top];
}

/* 单调栈模板 */
void Template(int *nums, int numsSize)
{
    Stack s;
    for (int i = 0; i < numsSize; i++) {
        while (!IsEmpty(&s) && nums[i] <= Top(&s)) {
            Pop(&s);
        }
        Push(&s, nums[i]);
    }
}

