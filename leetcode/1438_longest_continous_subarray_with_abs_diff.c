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
