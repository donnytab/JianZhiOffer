/*
JZ74 和为S的连续正数序列

输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序


滑动窗口
初始化，i=1,j=1, 表示窗口大小为0
如果窗口中值的和小于目标值sum， 表示需要扩大窗口，j += 1
否则，如果狂口值和大于目标值sum，表示需要缩小窗口，i += 1
什么时候窗口终止呢，这里窗口左边界走到sum的一半即可终止，因为题目要求至少包含2个数
时间复杂度：O(N)
空间复杂度：O(1)
*/
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> ret;
        int l = 1, r = 1, win = 0;
        while(l <= sum>>1) {
            if (win < sum) { win += r++; }
            else if (win > sum) { win -= l++; }
            else {
                vector<int> ans;
                for(int k = l; k < r; ++k) {
                    ans.emplace_back(k);
                }
                ret.emplace_back(ans);
                win -= l++;
            }
        }
        return ret;
    }
};