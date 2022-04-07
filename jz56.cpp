/*
JZ56 数组中只出现一次的两个数字

一个整型数组里除了两个数字只出现一次，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。

对于这个题来说，如果把数字全异或起来，最后异或出来的结果是不同的那两个数的异或，然后随便从异或结果里面找一位1，
因为某一位上异或结果是1的话，说明要找两个数，这一位上一个是1，一个是0。
那么就可以把原来数组中，这一位是1的分成一组，这一位是0的分成一组。这样就有了两组每一组中会包含一个不同的数和一部分出现两次的数。 
然后组内异或就可以了。
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
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        int XOR = 0, a = 0, b = 0;
        vector<int> ret;
        for(auto num : array) {
            XOR ^= num;
        }
        int mask = 1;
        while(XOR & mask == 0) { //找到异或结果中二进制位为1的数字
            mask <<= 1;
        }
        for(auto num : array) {
            if(mask & num) { //根据异或性质 相同为0，不同为1 分别反推出两个数的结果
                a ^= num;
            } else {
                b ^= num;
            }
        }
        ret.emplace_back(min(a, b));
        ret.emplace_back(max(a, b));
        return ret;
    }
};