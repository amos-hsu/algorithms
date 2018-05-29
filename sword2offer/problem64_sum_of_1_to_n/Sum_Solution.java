/**
 * 求1+2+3+...+n=? 
 * 
 * 使用逻辑与的短路特性，实现递归的终止：
 *      若n==0，sum>0为false，后面的递归不执行，直接返回0；
 *      若n>0，执行sum += Sum_Solution(--n)，实现递归计算
 */

public class Solution {
    public int Sum_Solution(int n) {
        int sum = n;
        boolean flag  = (sum > 0) && ((sum += Sum_Solution(--n)) > 0);
        return sum;
    }
}