import java.util.ArrayList;
public class Solution {
    public int minNumberInRotateArray(int [] array) {
        if(array == null || array.length <= 0) return 0;
        int l = 0;
        int h = array.length - 1;
        int m = l;
        while(array[l] >= array[h]){
            if(h - l == 1){
                return array[h];
            }
            m = l + (h - l) / 2;
            if(array[l] == array[h] && array[h] == array[m]){
                for(int i=l; i<=h; i++)
                    if(array[l] > array[i])
                        return array[i];
            }
            if(array[m] >= array[l])
                l = m;
            else if(array[m] <= array[h])
                h = m;
        }
        return array[l];
    }
}