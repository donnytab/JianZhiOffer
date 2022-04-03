/*
JZ29 顺时针打印矩阵

描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵：
[[1,2,3,4],
[5,6,7,8],
[9,10,11,12],
[13,14,15,16]]

则依次打印出数字
[1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10]
*/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = n - 1, t = 0, b = m - 1, x = 0;
        vector<int> res((r+1)*(b+1), 0);
        if(m == 0 || n == 0) {
            return res;
        }
        while(true) {
            for(int i = l; i <= r; i++) res[x++] = matrix[t][i]; // left to right.
            if(++t > b) break;
            for(int i = t; i <= b; i++) res[x++] = matrix[i][r]; // top to bottom.
            if(l > --r) break;
            for(int i = r; i >= l; i--) res[x++] = matrix[b][i]; // right to left.
            if(t > --b) break;
            for(int i = b; i >= t; i--) res[x++] = matrix[i][l]; // bottom to top.
            if(++l > r) break;
        }
        return res;
    }
};