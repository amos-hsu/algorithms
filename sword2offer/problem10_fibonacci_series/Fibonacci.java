/**
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
 * n<=39
 */
public class Solution {
    public int Fibonacci(int n) {
        if(n <= 1) return n;
        int last = 0;
        int nextToLast = 1;
        int fib = 0;
        for(int i = 2; i <= n; i ++) {
            fib = last + nextToLast;
            last = nextToLast;
            nextToLast = fib;
        }
        return fib;
    }
}
