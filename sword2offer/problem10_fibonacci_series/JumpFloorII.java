/**
 * 变态跳台阶问题：
 * 一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级... 它也可以跳上 n 级。
 * 求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
 * 
 * 一次性跳完记作f(0)=1
 * n=1 1
 * n=2 2
 * n>2,第一次跳1个，f(n-1);第一次跳两个，f(n-1);...;第一次跳n个，f(0)
 *      f(n)=f(n-1)+f(n-2)+...+f(0)
 *      或者
 *      f(n-1)=f(n-2)+f(n-3)+...f(0)
 *      从而f(n)=f(n-1)*2
 *      [f(n)=2^(n-1)]
 */

public class Solution {
    //O(N)+O(1)
    public int JumpFloor2(int n) {
        if(n <= 1) return n;
        int pre = 1;
        int res = 0;
        for(int i = 2; i <= n; i ++) {
            res = pre * 2;
            pre = res;
        }
        return res;
    }
}
