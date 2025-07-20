/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <stack>
using namespace std;
class MinStack { // Adapter
    struct NodeMin
    {
        int data{};
        int min{};
    };

    stack<NodeMin> m_stack{};
public:
    MinStack():m_stack{}{
    }
    
    void push(int val) {
        int min = (!m_stack.empty())?m_stack.top().min:val;
        if(val < min){
           min = val; 
        }
        m_stack.emplace(val,min);
    }
    
    void pop() {
        m_stack.pop();    
    }
    
    int top() {
       return m_stack.top().data; 
    }
    
    int getMin() {
       return m_stack.top().min; 
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
// @lc code=end

