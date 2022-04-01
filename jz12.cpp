/*
JZ12 矩阵中的路径

请设计一个函数，用来判断在一个n乘m的矩阵中是否存在一条包含某长度为len的字符串所有字符的路径
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
*/

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 
     * @return bool布尔型
     */
    bool hasPath(vector<vector<char> >& matrix, string word) {
        if(matrix.empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool find = false;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                backtrack(i, j, matrix, visited, word, find, 0); 
            }
        }
        return find;
    }
    
    void backtrack(int i, int j, vector<vector<char>>& matrix, 
                   vector<vector<bool>>& visited,
                   string& word, bool& find, int pos) {
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()) {
            return;
        }
        if(visited[i][j] || find || matrix[i][j] != word[pos]) {
            return;
        }
        if(pos == word.size() - 1) {
            find = true;
            return;
        }
        visited[i][j] = true;
        backtrack(i+1, j, matrix, visited, word, find, pos+1);
        backtrack(i-1, j, matrix, visited, word, find, pos+1);
        backtrack(i, j+1, matrix, visited, word, find, pos+1); 
        backtrack(i, j-1, matrix, visited, word, find, pos+1);
        visited[i][j] = false;
    }
};