/*
JZ4 二维数组中的查找

在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
[
[1,2,8,9],
[2,4,9,12],
[4,7,10,13],
[6,8,11,15]
]
给定 target = 7，返回 true。

给定 target = 3，返回 false。
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size();
        int n = array[0].size();
        int j = n - 1, i = 0;
        while(j >= 0 && i < m) {
            if(array[i][j] == target) {
                return true;
            } else if(array[i][j] < target) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
    }
};