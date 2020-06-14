int reverse(int x){
    int res = 0;
    while (x != 0) {
        if ((res > INT_MAX / 10)  || ((res == INT_MAX / 10)
            && (x % 10 > 7))) {
            return 0;
        }
        if ((res < INT_MIN / 10)  || ((res == INT_MIN / 10)
            && (x % 10 < -8))) {
            return 0;
        }
        res = res * 10 + x % 10;
        x = x / 10;
    }
    return res;
}