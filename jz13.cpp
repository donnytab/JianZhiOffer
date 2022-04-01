/*
JZ13 机器人的运动范围

描述 
地上有一个 rows 行和 cols 列的方格。坐标从 [0,0] 到 [rows-1,cols-1] 。一个机器人从坐标 [0,0] 的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于 threshold 的格子。 例如，当 threshold 为 18 时，机器人能够进入方格   [35,37] ，因为 3+5+3+7 = 18。但是，它不能进入方格 [35,38] ，因为 3+5+3+8 = 19 。请问该机器人能够达到多少个格子？

数据范围： 0 <= threshold <=15  ，1 <=rows,cols <=100 

进阶：空间复杂度 O(nm) ，时间复杂度 O(nm) 

输入：
10,1,100
复制
返回值：
29
复制
说明：
[0,0],[0,1],[0,2],[0,3],[0,4],[0,5],[0,6],[0,7],[0,8],[0,9],[0,10],[0,11],[0,12],[0,13],[0,14],[0,15],[0,16],[0,17],[0,18],[0,19],[0,20],[0,21],[0,22],[0,23],[0,24],[0,25],[0,26],[0,27],[0,28] 这29种，后面的[0,29],[0,30]以及[0,31]等等是无法到达的  
*/

class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        if (rows <= 0 || cols <= 0 || threshold < 0)
            return 0;
 
        vector<vector<bool>> isVisited(rows, vector<bool>(cols, false));
        int count = helper(threshold, rows, cols, 0, 0, isVisited);
        return count;   
    }
    
    int helper(int threshold,int rows,int cols, int row,int col, vector<vector<bool>>& isVisited) {
        if (row < 0 || col < 0 || row >= rows || col >= cols || isVisited[row][col]
                || sum_digit(row) + sum_digit(col) > threshold) {
            return 0;
        }
        isVisited[row][col] = true;
        return 1 + helper(threshold, rows, cols, row - 1, col, isVisited)
                + helper(threshold, rows, cols, row + 1, col, isVisited)
                + helper(threshold, rows, cols, row, col - 1, isVisited)
                + helper(threshold, rows, cols, row, col + 1, isVisited);
    }
    
    int sum_digit(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
};