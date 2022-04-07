/*
JZ59 滑动窗口的最大值

给定一个长度为 n 的数组 nums 和滑动窗口的大小 size ，找出所有滑动窗口里数值的最大值。
*/
class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        deque<int> dq; //双端队列
        vector<int> ret;
        for(int i = 0; i < nums.size(); ++i){
            while(!dq.empty() &&  i - k >= dq.front()) {
                dq.pop_front(); //判断队头是否在滑动窗口范围内
            }
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();//维护单调递减队列
            }
            dq.push_back(i); //将当前元素插入队尾
            if(i >= k - 1) {
                ret.emplace_back(nums[dq.front()]); //滑动窗口的元素达到了k个，才可以将其加入答案数组中
            }
        }
        return ret;
    }
};