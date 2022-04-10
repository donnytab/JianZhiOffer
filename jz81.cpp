/*
JZ81 调整数组顺序使奇数位于偶数前面(二)

输入一个长度为 n 整数数组，数组里面可能含有相同的元素，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前面部分，所有的偶数位于数组的后面部分，对奇数和奇数，
偶数和偶数之间的相对位置不做要求，但是时间复杂度和空间复杂度必须如下要求。
要求：时间复杂度 O(n)，空间复杂度 O(1)


思路很简单，双指针，从数组两头向中间靠近。左边的为奇数指针，右边的为偶数指针。
左边指针在没有遇到偶数时，就向右移动，遇到偶数立即停止；右边指针再没有遇到奇数时，向左边移动，遇到奇数时，进行奇偶指针元素交换。
交换之后切换到奇数指针工作。这个方法只遍历一遍数组，时间o(n),空间o(1)。
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
    vector<int> reOrderArrayTwo(vector<int>& array) {
        int odd_ptr = 0, even_ptr = array.size() - 1;
        while(odd_ptr < even_ptr) {
            while(odd_ptr < even_ptr && array[odd_ptr] % 2) {
                ++odd_ptr;
            }
            while(odd_ptr < even_ptr && array[even_ptr] % 2 == 0) {
                --even_ptr;
            }
            if(odd_ptr < even_ptr) {
                swap(array[odd_ptr++], array[even_ptr--]);
            }
        }
        return array;
    }
};