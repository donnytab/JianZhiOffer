/*
JZ51 数组中的逆序对

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数。

归并排序
我们都知道，归并排序过程中，会有个合并左右子区间的过程，对于这个过程，我们详细分析

设指针分别在左右儿子区间上面移动，当时，此时我们就需要将a[j]放入合并后的数组中

不难发现，左区间的数的下标都是小于右区间的，并且满足单调性

我们如果需要知道第一个大于的数，设为，那么左区间中以后的所有数，都比a[j]大（因为左区间已经满足单调性）

故此时，左区间中，与构成逆序对的数字的个数为左半边剩下的数，mid-i+1


*/
class Solution {
private:
    long long ans;
public:
    int InversePairs(vector<int> data) {
        int sz = data.size();
        vector<int> tmp(sz, 0); //辅助数组, 用于合并阶段暂存元素
        merge_sort(data, tmp, 0, sz-1);
        return ans;
    }
    
    void merge_sort(vector<int>& data, vector<int>& tmp, int l, int r) {
        if(l < r) {
            int mid = l + (r - l>>1);
            merge_sort(data, tmp, l, mid);
            merge_sort(data, tmp, mid+1, r);
            merge(data, tmp, l, r);
        }
        return;
    }
    
    void merge(vector<int>& data, vector<int>& tmp, int l, int r) {
        int mid = l + (r - l>>1);
        int i = l, j = mid+1, k = l;
        while(i <= mid && j <= r) {
            if(data[i] > data[j]) { //右半边的数更小
                tmp[k++] = data[j++];
                ans += mid - i + 1; //左半边剩余的数，都比这个数大，构成逆序，左半边剩余的数==(右端-左端+1)=（mid-i+1）
                //ans %= (long long)1e9+7;
            } else {
                tmp[k++] = data[i++];
            }
        }
        while(i <= mid) tmp[k++] = data[i++]; //如果左半边还有剩余
        while(j <= r) tmp[k++] = data[j++]; //右半边还有剩余
        for(i = l; i <= r; ++i) {
            data[i] = tmp[i]; //辅助数组拷贝到原数组
        }
        return;
    }
};