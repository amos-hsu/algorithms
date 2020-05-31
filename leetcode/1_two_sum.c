int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *retNums = (int *)malloc(2 * sizeof(int));
    if (retNums == NULL) return NULL;
    *returnSize = 0;
    int i, j;
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                retNums[0] = i;
                retNums[1] = j;
                *returnSize = 2;
                return retNums;
            }
        }
    }
    return NULL;
}