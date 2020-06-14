// 约瑟夫环
int lastRemaining(int n, int m)
{
    // f(n - 1, m) = x
    // f(n, m) = ((m - 1) % n + x + 1) % m = (m + x) % n
    int x = 0;
    int i;
    for (i = 2; i <= n; i++) {
        x = (m + x) % i;
    }
    return x;
}