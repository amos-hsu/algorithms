import org.omg.CORBA.TIMEOUT;

//把一根绳子剪成多段，并且使得每段的长度乘积最大。

class Sulotion{
    public int stringCuttingDynamic(int len){//思路：动态规划算法
        if(len<2) return 0;
        if(len == 2) return 1;
        if(len == 3) return 2;
        int[] product = new int[len+1];
        product[0] = 0;
        product[1] = 1;
        product[2] = 2;
        product[3] = 3;
        for(int i=4; i<=len; i++){
            int max = 0;
            for(int j =1; j <= i / 2; j++){
                int p = product[j] * product[i-j];
                if(p > max)
                    max = p;
                product[i] = max;
            }
        }
        return product[len];
    }
    public int stringCuttingByGreedy(int len){ //贪婪算法实现
        if(len<2) return 0;
        if(len == 2) return 1;
        if(len == 3) return 2;
        //3的段数
        int timeOf3 = len /3;
        //最后一段为4时，剪为2*2
        if(len - 3*timeOf3 == 1) timeOf3 -= 1;
        //2的段数
        int timeOf2 = (len - 3*timeOf3) / 2
        
        int max = (int)(Math.pow(3, timeOf3)) * (int)(Math.pow(2, timeOf2));
        return max;
    } 
}