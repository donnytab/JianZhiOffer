/*
JZ11 旋转数组的最小数字

有一个长度为 n 的非降序数组，比如[1,2,3,4,5]，将它进行旋转，
即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组，
比如变成了[3,4,5,1,2]，或者[4,5,1,2,3]这样的。
请问，给定这样一个旋转数组，求数组中的最小值。
*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0) {
            return 0;
        }
        int left = 0, right = rotateArray.size() - 1;
        while(left < right) {// 最后剩下一个元素，即为答案
            if(rotateArray[left] < rotateArray[right]) {
                return rotateArray[left];
            }
            int mid = left + ((right - left) >> 1);
            if(rotateArray[mid] > rotateArray[right]) {
                left = mid + 1;
            } else if(rotateArray[mid] < rotateArray[right]) {
                right = mid;
            } else {
                --right;
            }
        }
        return rotateArray[left];
    }
};
