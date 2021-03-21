int Compare(const void *a, const void *b)
{
    int **arr1 = (int **)a;
    int **arr2 = (int **)b;
    return *arr1[0] - *arr2[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    int **res = (int **)malloc(sizeof(int *) * intervalsSize);
    int resIdx = 0;
    int diff = 1;
    if (intervals == NULL || intervalsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = intervalsColSize;
        return NULL;
    }
    qsort(intervals, intervalsSize, sizeof(int *), Compare);
    for (int i = 0; i < intervalsSize; i+=diff) {
        diff = 1;
        for (int j = i + 1; j < intervalsSize; j++) {
            if (intervals[i][1] < intervals[j][0]) {
                break;
            }
            if (intervals[i][1] > intervals[j][1]) { // i多跳一步
                diff++;
                continue;
            }
            if (intervals[i][1] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]) {  // i多跳一步
                intervals[i][1] = intervals[j][1];
                diff++;
                continue;
            }
        }
        res[resIdx++] = intervals[i];
    }
    *returnSize = resIdx;
    *returnColumnSizes = intervalsColSize;
    return res;
}