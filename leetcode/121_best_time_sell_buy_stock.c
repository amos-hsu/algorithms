// 方法一：暴力穷举
#define MAX(a, b) ((a) > (b)) ? (a) : (b)
int maxProfit(int* prices, int pricesSize)
{
    int res = 0;
    int profit = 0;
    for (int i = 0; i < pricesSize; i++) {
        profit = 0;
        for (int j = i + 1; j < pricesSize; j++) {
            profit = prices[j] - prices[i];
            if (profit > 0) res = MAX(profit, res);
        }
    }
    return res;
}
// 方法二：动态规划
int maxProfit(int* prices, int pricesSize)
{
    int res = 0;
    int dp = 0;
    for (int i = 0; i < pricesSize; i++) {
        if (i > 0) {
            dp = MAX(0, dp + prices[i] - prices[i - 1]);
        }
        res = MAX(dp, res);
    }
    return res;
}