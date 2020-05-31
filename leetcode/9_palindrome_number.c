// 方法一：数字全部翻转，需要考虑溢出
bool isPalindrome(int x){
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    int ori = x;
    int res;
    for (res = 0; x > 0; x = x /10) {
        if ((res > INT_MAX / 10) || (res == INT_MAX / 10 && x % 10 > 7))
            return false;
        res = res * 10 + x % 10;
    }
    return (ori == res);
}

// 方法二：翻转一半数字，不需要考虑溢出
bool isPalindrome(int x){
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    int res = 0;
    while (res < x) {
        res = res * 10 + x % 10;
        x = x / 10;
    }
    // 偶数位，两部分相等则成功；奇数位，差10倍则成功
    return (res == x || res / 10 == x);
}