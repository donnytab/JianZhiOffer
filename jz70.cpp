/*
JZ70 矩形覆盖

我们可以用 2*1 的小矩形横着或者竖着去覆盖更大的矩形。
请问用 n 个 2*1 的小矩形无重叠地覆盖一个 2*n 的大矩形，
从同一个方向看总共有多少种不同的方法？

同 青蛙跳台阶 jz69
*/
class Solution {
public:
    int rectCover(int number) {
        if(number <= 0) return 0;
        int c1 = 1, c2 = 1, tmp = 1;
        for(int i = 2; i <= number; ++i) {
            tmp = c1 + c2;
            c1 = c2;
            c2 = tmp;
        }
        return c2;
    }
};