/**
 * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 */
public class Solution {
    public int NumberOf1ByShift(int n) {
        int bitFlag = 1;
        int cnt = 0;
        while(bitFlag != 0){
            if((n & bitFlag) != 0)
                cnt ++;
            bitFlag = bitFlag << 1;
        }
        return cnt;
    }
    public int NumerOf1ByBit(int n){
        int cnt = 0;
        while(n != 0){
            cnt++;
            n = (n-1) & n;
        }
        return cnt;
    }
}