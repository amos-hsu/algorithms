/**
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
 * 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 * 
 * 分析：
 * n=0 f(0)=0
 * n=1 f(1)=1
 * n=2 f(2)=2
 * n>2 第一个竖放，右边还有2x(n-1)，有f(n-1)种；
 *      第一个横放，右边还有2x(n-2),有f(n-2)种
 *      所以f(n)=f(n-1)+f(n-2)
 *      是一个斐波那契数列，迭代初始值：1,2
 * 
 */
public class RectCover {
    public int rectCover(int n) {
        if(n == 0) return 1;
        if(n<=2) return n;
        int pre1 = 1;
        int pre2 = 2;
        int res = 0;
        for(int i=3; i<=n; i++){
            res = pre1 + pre2;
            pre1 = pre2;
            pre2 = res;
        }
        return res; 
    }
}