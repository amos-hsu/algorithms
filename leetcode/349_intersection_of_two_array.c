// 排序 + 双指针
int cmp(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if (nums1 == NULL || nums2 == NULL || returnSize == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int count = 0;
    int i = 0, j = 0;
    int *ans = (int *)malloc(sizeof(int) * (nums1Size > nums2Size ? nums1Size : nums2Size));
    qsort((void *)nums1, nums1Size, sizeof(int), cmp);
    qsort((void *)nums2, nums2Size, sizeof(int), cmp);
    while(i < nums1Size && j < nums2Size) {  // 双指针
        if (nums1[i] > nums2[j]) {
            j += 1;
        } else if (nums1[i] < nums2[j]) {
            i += 1;
        } else {
            ans[count] = nums1[i];
            i += 1;
            j += 1;
            if (count >= 1 && (ans[count] == ans[count -1])) {  // 去重
                count -= 1;
            }
            count += 1;
        }
    }
    *returnSize = count;
    return ans;
}