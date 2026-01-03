// 295. 数据流的中位数
// 困难

// 中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。

// 例如 arr = [2,3,4] 的中位数是 3 。
// 例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
// 实现 MedianFinder 类:

// MedianFinder() 初始化 MedianFinder 对象。

// void addNum(int num) 将数据流中的整数 num 添加到数据结构中。

// double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10-5 以内的答案将被接受。

#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> queMin; 
    priority_queue<int, vector<int>, greater<int>> queMax; // greater<int> 表示优先弹出最小元素） 
    MedianFinder() {}
    
    void addNum(int num) {
        if(queMin.empty() || num <= queMin.top()){
            queMin.push(num);
            if(queMax.size() + 1 <queMin.size()){
                queMax.push(queMin.top());
                queMin.pop();
            }
        }else{
            queMax.push(num);
            if(queMax.size() > queMin.size()){
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }
    
    double findMedian() {
        if(queMax.size() > queMin.size()){
            return queMin.top();
        }
        return (queMin.top() + queMax.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */