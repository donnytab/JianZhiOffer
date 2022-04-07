/*
JZ61 扑克牌顺子

描述
现在有2副扑克牌，从扑克牌中随机五张扑克牌，我们需要来判断一下是不是顺子。
有如下规则：
1. A为1，J为11，Q为12，K为13，A不能视为14
2. 大、小王为 0，0可以看作任意牌
3. 如果给出的五张牌能组成顺子（即这五张牌是连续的）就输出true，否则就输出false。
4.数据保证每组5个数字，每组最多含有4个零，数组的数取值为 [0, 13]
*/
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        sort(numbers.begin(), numbers.end());
        int ghost = 0, sz = numbers.size();
        for(int i = 0; i < sz-1; ++i) {
            if(numbers[i] == 0) {
                ++ghost;
            } else if(numbers[i] == numbers[i+1]) {
                return false;
            }
        }
        return numbers[sz-1] - numbers[ghost] < 5; 
    }

/*
// 采用set+遍历
// 时间复杂度 O(N) 空间复杂度 O(N) 
    bool IsContinuous( vector<int> numbers ) {
        set<int> se;
        int _min=14,_max=0;//一副牌最大K点，所以_min初始化14；
        for(auto i:numbers){//C++11语法
            if(i==0)continue;//大小王
            _min=min(_min,i);//最小牌
            _max=max(_max,i);//最大牌
            if(se.count(i))return false;//出现重复牌
            se.insert(i);
        }
        return _max-_min<5;//顺子中最大的牌点数max - 顺子中最小的牌点数min < 5
    }
*/
};