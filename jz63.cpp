/*
JZ63 买卖股票的最好时机(一)

假设你有一个数组prices，长度为n，其中prices[i]是股票在第i天的价格
请根据这个价格数组，返回买卖股票能获得的最大收益


显然，如果我们真的在买卖股票，我们肯定会想：如果我是在历史最低点买的股票就好了！太好了，
在题目中，我们只要用一个变量记录一个历史最低价格 minprice，我们就可以假设自己的股票是在那天买的。那么我们在第 i 天卖出股票能得到的利润就是 prices[i] - minprice。

因此，我们只需要遍历价格数组一遍，记录历史最低点，然后在每一天考虑这么一个问题：如果我是在历史最低点买进的，那么我今天卖出能赚多少钱？
当考虑完所有天数之时，我们就得到了最好的答案。

时间复杂度：O(n)，只需要遍历一次。
空间复杂度：O(1)，只使用了常数个变量。
*/
class Solution {
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX, max_profit = 0;
        for(auto price : prices) {
            max_profit = max(max_profit, price - min_price);
            min_price = min(min_price, price);
        }
        return max_profit;
    }
    
/*
    // 我们可以遍历一遍数组，在每一个位置 i 时，记录 i 位置之前所有价格中的最低价格，
    // 然后 将当前的价格作为售出价格，查看当前收益是不是最大收益即可。 
    int maxProfit(vector<int>& prices) {
        int sell = 0, buy = INT_MIN;
        for (int i = 0; i < prices.size(); ++i) {
            buy = max(buy, -prices[i]);
           sell = max(sell, buy + prices[i]);
        }
        return sell;
    }
*/
};