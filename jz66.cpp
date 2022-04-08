/*
JZ66 构建乘积数组

给定一个数组 A[0,1,...,n-1] ,请构建一个数组 B[0,1,...,n-1]
其中 B 的元素 B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]

输入：
[1,2,3,4,5]
返回值：
[120,60,40,30,24]

forward:  1,   2,    6,   24,  120
backward: 120, 120,  60,  20,  5

left[i+1] = left[i] * A[i]
right[i] = right[i+1] * A[i+1]
*/
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int sz = A.size();
        vector<int> ret(sz, 1);
        for(int j = 1; j < sz; ++j) {
            ret[j] = ret[j-1] * A[j-1]; // left[i]用B[i]代替
        }
        int right = 1;
        for(int i = sz - 2; i >= 0; --i) {
            right *= A[i+1]; // right[i]用tmp代替
            ret[i] *= right;
        }
        return ret;
    }
};