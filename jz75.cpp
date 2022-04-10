/*
JZ75 字符流中第一个不重复的字符

请实现一个函数用来找出字符流中第一个只出现一次的字符

方法：哈希+队列
针对题目的描述，我们先提出两个问题？

Q1. 给定一个字符串（只不过这里的字符串是可变的），如果快速判断一个字符是否存在于字符串中，如果存在，也就是重复？
Q2. 这里先不考虑重复，如果快速返回第一个字符？有没有感觉有点像先来先服务？

对于一道题，如果没有思路，就要针对题目给自己问问题。然后针对问题，来考虑需要什么样的算法或者数据结构。

A1：对于“重复问题”，惯性思维应该想到哈希或者set。对于“字符串问题”，大多会用到哈希。因此一结合，应该可以想到，判断一个字符是否重复，可以选择用哈希，在c++中，可以选择用unordered_map<char, int>

A2：对于字符流，源源不断的往池子中添加字符，然后还要返回第一个满足什么条件的字符，显然设计到了“顺序”，也就是先来的先服务，这种先进先出的数据结构不就是队列嘛。因此，这里可以用队列。
*/
class Solution
{
private:
    unordered_map<char, int> map;
    queue<char> q;
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
         if(map.find(ch) == map.end()) {
             q.push(ch);    // 如果是第一次出现， 则添加到队列中
         }
         ++map[ch];
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!q.empty()) {
            char c = q.front();
            if(map[c] == 1) {
                return c;
            } else {
                q.pop();
            }
        }
        return '#';
    }

};