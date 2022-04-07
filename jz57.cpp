/*
JZ57 和为S的两个数字

输入一个升序数组 array 和一个数字S，在数组中查找两个数，使得他们的和正好是S，
如果有多对数字的和等于S，返回任意一组即可，
如果无法找出这样的数字，返回一个空数组即可。
*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> ret;
        if (array.size() == 0) {
            return ret;
        }
        
        int high = array.size()-1;
        int low = 0;
        int mult = INT_MAX;
        while (high > low) {
            if (array.at(high) + array.at(low) == sum) {
                if (array.at(high)*array.at(low) < mult) {
                    mult =  array.at(high)*array.at(low);
                    ret.clear();
                    ret.push_back(array.at(low));
                    ret.push_back(array.at(high));
                }
                high--;
                low++;
            }
            if (array.at(high) + array.at(low) > sum) {
                high--;
            }
            if(array.at(high) + array.at(low) < sum) {
                low++;
            }
        }
        return ret;
    }
};