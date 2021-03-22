int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *res = malloc(sizeof(int) * 2);
    *returnSize = 2;
    int l = 0;
    int r = numsSize - 1;
    int max = -1;
    int min = numsSize;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            max = fmax(max, mid);
            min = fmin(min, mid);
            r = mid - 1;
        } else if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    l = 0;
    r = numsSize - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            max = fmax(max, mid);
            min = fmin(min, mid);
            l = mid + 1;
        } else if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    res[0] = min != numsSize ? min : -1;
    res[1] = max != -1 ? max : -1;
    return res;
}