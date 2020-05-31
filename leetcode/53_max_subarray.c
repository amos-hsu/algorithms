// 贪心（动态规划）
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxSubArray(int* nums, int numsSize){
    int ans = nums[0];
    int sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        sum = MAX(nums[i], nums[i] + sum);
        ans = MAX(ans, sum);
    }
    return ans;
}