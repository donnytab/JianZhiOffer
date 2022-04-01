class Solution
{
public:
    void push(int node) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }

        stack1.push(node);
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    int pop() {
        int element = -1;
        if (stack1.empty()) return element;
        element = stack1.top();
        stack1.pop();
        return element;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};