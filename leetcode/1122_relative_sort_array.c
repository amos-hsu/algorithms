int compare(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
    int *ans = (int*)malloc(arr1Size * sizeof(int));
    int ansLeft = 0;
    int ansRight = arr1Size - 1;
    int arr1hash[1001] = { 0 };
    int arr2hash[1001] = { 0 };
    (void)memset(ans, 0, arr1Size * sizeof(int));
    for (int i = 0; i < arr2Size; i ++) {
        arr2hash[arr2[i]]++;
    }
    for (int i = 0; i < arr1Size; i ++) {
        if (arr2hash[arr1[i]] == 0) {
            ans[ansRight--] = arr1[i];
        }
        arr1hash[arr1[i]]++;
    }
    for (int j = 0; j < arr2Size; j++) {
        for (int k = 0; k < arr1hash[arr2[j]]; k++) {
            ans[ansLeft++] = arr2[j];
        }
        arr1hash[arr2[j]] = 0;
    }
    printf("size=%d r=%d\n", arr1Size, ansRight);
    (void)qsort(&ans[ansRight + 1], arr1Size - ansRight - 1, sizeof(int), compare);
    *returnSize = arr1Size;
    return ans;
}