#include <stdio.h>
#define MAX(a, b) ((a) > (b)) ? (a) : (b)

void FindMaxMin(int *nums, int l, int r, int *max, int *min)
{
    int maxNum = nums[l];
    int minNum = nums[l];
    for (int i = l; i <= r; i++) {
        if (nums[i] > maxNum) maxNum = nums[i];
        if (nums[i] < minNum) minNum = nums[i];
    }
    *max = maxNum;
    *min = minNum;
}

int longestSubarray(int* nums, int numsSize, int limit){
    int l = 0;
    int r = 0;
    int max = nums[0];
    int min = nums[0];
    int windowSize = 0;
    while (r < numsSize) {
        int winR = nums[r];
        r++;
        if (max < winR) max = winR;
        if (min > winR) min = winR;
        // printf("-- max=%d min=%d\n", max, min);
        if (max - min <= limit) {
            windowSize = MAX(windowSize, r - l);
        }
        // printf("++ l=%d r=%d winSize=%d\n", l, r-1, windowSize);
        if (max - min > limit && r < numsSize) {
            l++;
            if (r - l < windowSize)
                r++;
            FindMaxMin(nums, l, r - 1, &max, &min);
        }
    }
    return windowSize;
}
int main()
{
    int nums[] = {10,1,2,4,7,2,2,2,2,2,2,2,2,2};
    int limit = 5;
    printf(">>> res = %d\n", longestSubarray(nums,
        sizeof(nums) / sizeof(int), limit));
    return 0;
}

/* 202101j解法 */
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int longestSubarray20200110(int* nums, int numsSize, int limit)
{
    // 最长子串长度 -- 滑动窗口
    // 子串属性：任意元素绝对差<=limit -> 最大和最小元素差<=limit
    int l = 0;
    int r = 0;
    int ans = 0; // 字串长度
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    int min = nums[0];
    int max = nums[0]; 
    // 滑动窗口
    while (r < numsSize) {
        // 窗口右边界更新为r，窗口内信息刷新
        min = MIN(min, nums[r]);
        max = MAX(max, nums[r]);
        r++; // 窗口右边界右移，左闭右开区间。窗口长度为r-l
        if (max - min <= limit && ans < r - l) {  // 子串属性符合条件，刷新窗口长度
            ans = r - l;
        }
        // printf("##l=%d r=%d ans=%d max=%2d min=%2d diff=%d\n", l, r , ans, max, min, max-min);
        while (r < numsSize && max - min > limit) { // 字串属性不满足条件, 需要收缩, 条件: 最大和最小元素差>limit
            // printf("++l=%d r=%d ans=%d max=%2d min=%2d diff=%d\n", l, r, ans, max, min, max-min);
            l++;
            r++;
            max = INT_MIN;
            min = INT_MAX;
            for (int i = l; i < r; i++) {
                max = nums[i] > max ? nums[i] : max;
                min = nums[i] < min ? nums[i] : min;
            }
            if (max - min <= limit && ans < r - l) { // 左右节点同时刷新，可能到达边界，需要刷新窗口条件
                ans = r - l;
            }
            // printf("==l=%d r=%d ans=%d max=%2d min=%2d diff=%d\n", l, r, ans, max, min, max-min);
        }
    }
    return ans;
}