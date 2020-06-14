// 斐波那契算法
int climbStairs(int n){
    if (n == 1) return 1;
    int one = 1;
    int two = 2;
    int i;
    int tmp;
    for (i = 3; i <= n; i++) {
        tmp = one + two;
        one = two;
        two = tmp;
    }
    return two;
}
// 动态规划
int climbStairs(int n){
    if (n < 1) return 1;
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    dp[1] = 1;
    dp[2] = 2;
    int i;
    for (i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}