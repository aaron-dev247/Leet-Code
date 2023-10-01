#include <vector>

using namespace std;

/**
 * Time Complexity of all functions are: O(1)
 * Space Complexity: O(n)
 */
class MinStack
{
private:
    vector<int> minValVec;
    vector<int> stackVec;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        stackVec.push_back(val);
        minValVec.push_back(min(val, minValVec.size() ? minValVec.back() : val));
    }

    void pop()
    {
        stackVec.pop_back();
        minValVec.pop_back();
    }

    int top()
    {
        return stackVec.back();
    }

    int getMin()
    {
        return minValVec.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */