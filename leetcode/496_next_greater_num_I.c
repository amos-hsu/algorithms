int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * nums2Size);
    int stack[nums2Size];
    int hash[10001] = { 0 };
    int top = -1;
    for (int i = nums2Size - 1; i >= 0; i--) {
        while (top != -1 && stack[top] <= nums2[i]) {
            top--;
        }
        hash[nums2[i]] = top == -1 ? -1 : stack[top];
        stack[++top] = nums2[i];
    }
    for (int i = 0; i < nums1Size; i++) {
        res[i] = hash[nums1[i]];
    }
    *returnSize = nums1Size;
    return res;
}
