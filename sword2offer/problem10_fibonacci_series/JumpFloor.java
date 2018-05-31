/**
 * 跳台阶问题：
 * 一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级。
 * 求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
 * 
 * n=1 1
 * n=2 2
 * n>2 第一次跳1个，有f(n-1)种;第一次跳2个，有f(n-2)种
 *     所以，f(n)=f(n-1)+f(n-2)
 * 
 * 注意：f(2)=f(1)+f(0)= 1+1 !
 */
public class Solution {
    public int JumpFloor(int n) {
        if(n <= 1) return n;
        int last = 1;
        int nextToLast = 1;
        int res = 0;
        for(int i = 2; i <= n; i ++) {
            res = last + nextToLast;
            last = nextToLast;
            nextToLast = res;
        }
        return res;
    }
}
