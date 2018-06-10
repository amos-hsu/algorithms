/**
 * 给定一个double类型的浮点数base和int类型的整数exponent。
 * 求base的exponent次方。
 * 
 * 
 */

public class Solution {
    public double Power(double base, int exponent) {
        if(base == 0 && exponent < 0)
            return 0;
        int expAbs = exponent;
        if(exponent < 0)
            expAbs = - exponent;
        double res = powerWithUnsignedExp(base, expAbs);
        return exponent<0 ? 1.0/res : res;
    }
    public double powerWithUnsignedExp(double base, int exp){
        if(exp == 1)
            return base;
        if(exp == 0)
            return 1.0;
        double res = powerWithUnsignedExp(base, exp>>1);
        res *= res;
        if((exp & 1) == 1)
            res *= base;
        return res;
    }
}