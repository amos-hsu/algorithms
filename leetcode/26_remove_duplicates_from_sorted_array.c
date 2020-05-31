// 双指针，快慢指针
int removeDuplicates(int* nums, int numsSize)
{
    if (nums == NULL || numsSize == 0) return 0;
    int fast;
    int slow = 0;
    for (fast = 1; fast < numsSize; fast++) {
        if (nums[slow] == nums[fast]) {
            continue;
        }
        slow++;
        nums[slow] = nums[fast];
    }
    return slow + 1;
}