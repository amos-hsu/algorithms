/**
* 不修改数组的情况下找出重复的数字
* 数组长度n+1,数字的范围在1~n，至少有一个重复数字
* 要求返回一个重复的数字

使用了二分查找方法
O(nlogn) + O(1)
*/
public class FindDuplicateNum2{
    public int getDuplication(int[] nums, int length){
        if(nums==null) return -1;
        for(int i=0; i<length; i++){
            if(nums[i]<1 || nums[i]>n)
                return -1;
        }
        int stat = 1;
        int end = length-1;
        while(start<end){
            int mid = (start + end)>>1;
            int count = coutRange(nums, start, mid);
            if(start == end){
                if(count > 1)
                    return start;
                else break;
            }
            if(count > (mid - start +1)){
                end = mid-1;
            }
            else
                start = mid+1;
        }

        return -1;
    }
    private int coutRange(int[] nums, int start, int end){
        if(nums==null) return 0;
        int count = 0;
        for(int i=0; i<nums.length; i++){
            if(nums[i]>=start && nums[i]<=end)
                count++;
        }
        return count;
    }
}