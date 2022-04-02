/*
JZ16 数值的整数次方
*/

class Solution {
public:
    double Power(double base, int exponent) {
        if(base == 0) {
            return 0.0;
        }
        if(exponent == 0) {
            return 1.0;
        }
        double ret = 1.0;
        if(exponent < 0) {
            base = 1 / base;
            exponent = -exponent;
        }
        while(exponent--) {
            ret *= base;
        }
        return ret;
    }
};