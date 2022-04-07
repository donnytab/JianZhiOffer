/*
JZ53 数字在升序数组中出现的次数

给定一个长度为 n 的非降序数组和一个非负数整数 k ，要求统计 k 在数组中出现的次数
*/
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int start = binary_search(data, k);  // 找到左边界
        int end = binary_search(data, k+1); // 找到右边界
        // 若超出数组范围，则证明目标值出现的次数为0，否则，右边界减去左边界即能统计出目标出现的次数
        return (start == data.size() || data[start] != k) ? 0 : end - start;
    }
    
    int binary_search(vector<int> data, int k) {
        int left = 0, right = data.size();
        while(left < right) {
            int mid = left + (right - left)/2;
            if(data[mid] >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};