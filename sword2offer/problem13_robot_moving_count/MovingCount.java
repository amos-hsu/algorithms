/**
 * 地上有一个m行和n列的方格。一个机器人从坐标(0,0)的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
 * 但是不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格(35,37)，因为3+5+3+7=18。
 * 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
 * 
 * 思路：
 * 减枝（回溯）
 * 
 * 回溯算法是深度优先搜索（dfs）的一种。
 */

public class Solution {
    public int movingCount(int threshold, int rows, int cols) {
        if(rows<=0 || cols<=0) return 0;
        boolean[][] visited = new boolean[rows][cols];
        int count = dfs(0, 0, threshold, rows, cols, visited);
        return count;
    }
    private int dfs(int row, int col, int threshold, int rows, int cols, boolean[][] visited){
        if(row<0 || col<0 || row>=rows || col>=cols || visited[row][col] || digitSum(row)+digitSum(col)>threshold)
            return 0;
        visited[row][col] = true;//标记
        int count = 1 + dfs(row+1, col, threshold, rows, cols, visited)
                    + dfs(row-1, col, threshold, rows, cols, visited)
                    + dfs(row, col+1, threshold, rows, cols, visited)
                    + dfs(row, col-1, threshold, rows, cols, visited);
        return count;
    }
    private int digitSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}