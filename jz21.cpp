/*
JZ21 调整数组顺序使奇数位于偶数前面(一)

描述
输入一个长度为 n 整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前面部分
所有的偶数位于数组的后面部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        vector<int> ret;
        for(auto const num : array) {
            if(num % 2 != 0) {
                ret.emplace_back(num);
            }
        }
        for(auto const num : array) {
            if(num % 2 == 0) {
                ret.emplace_back(num);
            }
        }
        return ret;
    }
    /* solution 2
    思路：使用双指针的方法，首先找出数组中第一个偶数的位置evenIndex以及在第一个偶数后面的第一个奇数位置oddIndex，
    将奇数oddIndex移动到evenIndex的位置，然后该奇数前面的所有偶数向后顺移一位。evenIndex加一，
    从oddIndex+1的位置开始寻找奇数的位置，为新的oddIndex。以此循环往复。
    时间复杂度：O(n^2)，来源于双指针对数组的遍历，以及对偶数的向后移动，最坏情况下偶数移动会有O(n^2)。
    空间复杂度：O(1)，常数个临时变量。
    vector<int> reOrderArray(vector<int>& array) 
    {
        // write code here
        int oddIndex=0,evenIndex=0;
        int n=array.size();
        if(n==0) return {};
        //找到第一个为偶数的
        while(array[evenIndex]%2){
            evenIndex++;
        }
        //找到在第一个偶数后的第一个奇数
        while(array[oddIndex]%2==0||oddIndex<evenIndex){
            oddIndex++;
        }
        //将奇数交换到第一个偶数的位置，在该奇数之前的所有偶数向后顺延一个位置
        while(oddIndex<n&&evenIndex<n){
            int tmp=array[oddIndex];
            for(int i=oddIndex;i>evenIndex;i--){
                array[i]=array[i-1];
            }
            array[evenIndex]=tmp;
            //对两个指针位置进行更新
            evenIndex++;
            while(oddIndex<n&&array[oddIndex]%2==0)
                oddIndex++;
        }
        return array;
    }
    */
};