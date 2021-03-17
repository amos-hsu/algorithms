void DumpStack(int *s, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
}
void DumpAns(int *s, int size)
{
    printf(">> ");
    for (int i = 0; i < size; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
}

int* dailyTemperatures(int* T, int TSize, int* returnSize)
{
    int *ans = (int *)malloc(sizeof(int) * TSize);
    int stack[TSize];   // 单调栈：单调递增栈
    int top = -1;
    (void)memset(ans, 0, TSize * sizeof(int));
    (void)memset(stack, 0, TSize * sizeof(int));
    for (int i = TSize - 1; i >= 0; i--) {
        // printf("i=%d\n", i);
        // DumpStack(stack, TSize);
        while (top != -1 && T[i] >= T[stack[top]]) {
            stack[top] = 0; // stack pop
            top--;
        }
        ans[i] = (top == -1) ? 0 : stack[top] - i;
        // DumpAns(ans, TSize);
        stack[++top] = i;  // stack push
    }
    *returnSize = TSize;
    return ans;
}
