//把一根绳子剪成多段，并且使得每段的长度乘积最大。

//思路：动态规划算法

class Sulotion{
    public int stringCutting(int len){
        if(len<2) return 0;
        if(len == 2) return 1;
        if(len == 3) return 2;
        int[] product = new int[len+1];
        product[0] = 0;
        product[1] = 0;
        product[2] = 1;
        product[3] = 2;
        for(int i=4; i<=len; i++){
            in

        }
    } 
}