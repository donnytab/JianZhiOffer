/*
JZ30 包含min函数的栈

描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的 min 函数，输入操作时保证 pop、top 和 min 函数操作时，栈中一定有元素。

此栈包含的方法有：
push(value):将value压入栈中
pop():弹出栈顶元素
top():获取栈顶元素
min():获取栈中最小元素
*/

class Solution {
private:
    stack<int> val_stack, min_stack;
public:
    Solution() {
        min_stack.push(INT_MAX);
    }
    void push(int value) {
        val_stack.push(value);
        min_stack.push(std::min(value, min_stack.top()));
    }
    void pop() {
        val_stack.pop();
        min_stack.pop();
    }
    int top() {
        return val_stack.top();
    }
    int min() {
        return min_stack.top();
    }
};