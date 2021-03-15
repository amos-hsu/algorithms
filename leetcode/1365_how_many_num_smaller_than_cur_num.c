int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int cnt[101] = { 0 };
    int i;
    int *res = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    memset(res, 0, sizeof(int) * numsSize);
    for (i = 0; i < numsSize; i++) {
        cnt[nums[i]]++;
    }
    for (i = 1; i < 101; i++) {
        cnt[i] = cnt[i] + cnt[i - 1];
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            res[i] = cnt[nums[i] - 1];
        } else {
            res[i] = 0;
        }
    }
    *returnSize = numsSize;
    return res;
}
