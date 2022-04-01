/*
JZ10 斐波那契数列
*/

class Solution {
public:
/*
    int Fibonacci(int n) {
        if(n == 1 || n == 2) {
            return 1;
        }
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
*/
    int Fibonacci(int n) {
        if(n == 0 || n == 1) {
            return n;
        }
        
        int dp1 = 1, dp2 = 0;
        for(int i = 2; i <= n; ++i) {
            int dp3 = dp1 + dp2;
            dp2 = dp1;
            dp1 = dp3;
        }
        return dp1;
    }
};