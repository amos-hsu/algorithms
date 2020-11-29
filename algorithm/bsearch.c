int search(int *nums, int numsSize, int target)
{
    int l = 0;
    int r = numsSize - 1;           // 左闭右闭区间
    while (l < r) {                 // 退出条件：r == l
        int mid = l + (r - l) / 2;
        if (nums[mid] > target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (nums[l] == target) return l;
    return -1;
}
