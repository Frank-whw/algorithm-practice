// 155. 最小栈

// 中等

// 设计一个支持 push ，pop ，top 操作，
// 并能在常数时间内检索到最小元素的栈。

// 实现 MinStack 类:

// MinStack() 初始化堆栈对象。
// void push(int val) 将元素val推入堆栈。
// void pop() 删除堆栈顶部的元素。
// int top() 获取堆栈顶部的元素。
// int getMin() 获取堆栈中的最小元素。

#include<bits/stdc++.h>
using namespace std;

class MinStack {

private:
    typedef struct Node{
        int val;
        int lastMin;
        Node* next;
    }Node;
    stack<Node*> sk;
    Node* top_node = nullptr;
    int min_num = INT_MAX;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(top_node == nullptr)    min_num = val;
        Node* node = new Node;
        node->lastMin = min_num;
        node->next = top_node;
        node->val = val;
        min_num = min(min_num, val);
        top_node = node;
    }
    
    void pop() {
        min_num = top_node->lastMin;
        top_node = top_node->next;
    }
    
    int top() {
        return top_node->val;
    }
    
    int getMin() {
        return min_num;
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


// 优化后的写法

class MinStack {
private:
    struct Node {
        int val;
        int min_val;
    };
    
    vector<Node> data;
    
public:
    MinStack () {
        
    }
    
    void push (int val) {
        
        int min_num;
        
        if (data.empty()) {
            min_num = val;
        }else {
            
            min_num = min(val, data.back().min_val);
        }
        
        data.push_back({val,min_num});
    }
    
    void pop () {
        data.pop_back();
    }
    
    int top () {
        return data.back().val;
    }
    
    int getMin () {
        return data.back().min_val;
    }
};
