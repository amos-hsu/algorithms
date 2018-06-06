/**
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下
 * 移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
 * 例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中
 * 不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
 * 路径不能再次进入该格子。
 * 
 * 思路：
 * 0 通过位置坐标，将一维字符数组模拟映射为矩阵
 * 1 定义布尔数组标记某个字符是否已经访问过
 * 2 在矩阵任选一个格子作为路径的起点，使用回溯算法，递归查找是否存在符合要求的路径。
 * 3 重复第二步。
 * 
 * 回溯算法：
 * 若路径上的第i个字符是ch，那么到相邻的格子找路径上的i+1个字符，如果找不到，递归终止。
 * 另外，矩阵边界越界或者访问到已经访问过的字符位置，递归终止。
 * 重复以上过程，直到路径字符串上的所有字符都在矩阵中找到合适的位置,此时i==str.length-1（成功后的递归终止条件）。
 */

public class Solution {
    public boolean hasPath(char[] matrix, int rows, int cols, char[] str){
        int[] visited = new int[matrix.length];
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++)
                if(backtrack(matrix, rows, cols, i, j, 0, str, visited))
                    return true;
        }
        return false;
    }
    private boolean backtrack(char[] matrix, int rows, int cols, int row, int col, int strIndex, char[] str, int[] visited){
        int index = row * cols + col;
        //递归基准条件
        if(row<0 || row>=rows || col<0 || col>=cols || matrix[index] != str[strIndex] || visited[index] == 1){
            return false;
        }
        if(strIndex == str.length - 1) 
            return true;
        //递归过程
        visited[index] = 1; //标记已遍历的字符位置
        boolean isHasPath = backtrack(matrix, rows, cols, row+1, col, strIndex+1, str, visited)
                            || backtrack(matrix, rows, cols, row-1, col, strIndex+1, str, visited)
                            || backtrack(matrix, rows, cols, row, col+1, strIndex+1, str, visited)
                            || backtrack(matrix, rows, cols, row, col-1, strIndex+1, str, visited);
        if(isHasPath == true)
            return true;
        visited[index] = 0; //没有找到下一个结点，取消标记（回溯到上一个遍历点）
        return false;
    }
}