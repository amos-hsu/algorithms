int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL || numsSize == 0) {
        *returnSize = 0;
        return nums;
    }
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    int stack[numsSize];
    int top = -1;
    (void)memset(ans, 0, numsSize * sizeof(int));
    (void)memset(stack, 0, numsSize * sizeof(int));
    for (int i = numsSize*2 - 1; i >= 0; i--) {
        // printf("i=%d\n", i);
        // Dump(stack, numsSize);
        while (top != -1 && nums[i % numsSize] >= nums[stack[top]]) {
            stack[top] = 0;
            top--;
        }
        ans[i % numsSize] = (top == -1) ? -1 : nums[stack[top]];
        // printf(">>");
        // Dump(ans, numsSize);
        stack[++top] = i % numsSize;
    }
    *returnSize = numsSize;
    return ans;
}