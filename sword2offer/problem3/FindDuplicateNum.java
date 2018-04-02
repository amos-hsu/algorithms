/* 题目：
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2
*/
/* 分析：
时间复杂度+空间复杂度
1、排序法：O(nlogn)+O(1)
2、哈希表法：O(n)+O(n)
    新开辟一个n长的数组作为哈希表；
    遍历数组，判断哈希表下标等于该值的位置是否有当前位的数字；
    如果哈希表没有该元素值，按其值放入哈希表；位置下标等于该值；
    如果哈希表已有该值，则找到一个重复数字。
3、利用哈希表特性的in-place方法：O(n)+O(1)
    遍历数组；
    判断当前值arr[i]是否与下标i相等；
    若相等，遍历下一位；
    若不相等，判断i与arr[i]是否相等，若相等，则找到一个重复数字，若不相等，则交换arr[i]和arr[arr[i]]的值，回到第2步。
    （相当于把arr[i]放到哈希表对应的位置）
下面采用了方法3：
*/
public class Solution {
    // Parameters:
    //    numbers:     an array of integers
    //    length:      the length of array numbers
    //    duplication: (Output) the duplicated number in the array number,length of duplication array is 1,so using duplication[0] = ? in implementation;
    //                  Here duplication like pointor in C/C++, duplication[0] equal *duplication in C/C++
    //    这里要特别注意~返回任意重复的一个，赋值duplication[0]
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    public boolean duplicate(int numbers[],int length,int [] duplication) {
        if(numbers==null || length<=0)
            return false;
        for(int i=0; i<length; i++){
            if(numbers[i]>length-1 || numbers[i]<0)
                return false;
        }
        for(int i=0; i<length; i++){
            while(numbers[i]!=i){
                if(numbers[i]==numbers[numbers[i]]){
                    duplication[0] = numbers[i];
                    return true;
                }
                int temp = numbers[i];
                numbers[i] =numbers[temp];
                numbers[temp] = temp;
            }
        }
        return false;
    }
}
