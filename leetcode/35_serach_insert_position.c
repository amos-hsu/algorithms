// 在排序数组中找到目标值索引，如果目标值不存在，返回其按顺序插入的索引
// 二分查找
int searchInsert(int* nums, int numsSize, int target)
{
    int l = 0;
    int r = numsSize;
    while (l < r) {
        int mid = l + (r - l) >> 1;
        if (nums[mid] < target) {
            l = mid + 1;
        } else if (nums[mid] > target) {
            r = mid;
        } else {
            return mid;
        }
    }
    return r;
}
