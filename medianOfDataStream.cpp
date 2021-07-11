//Source : https://leetcode.com/problems/find-median-from-data-stream/
//Author : Ayan Agrawal
//Date   : 11-07-2021

//Maintain a max heap for left half 
//Maintain a min heap for right half 
//insert in them such that difference between their size is not more than one

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> mn_heap;
    priority_queue<int> mx_heap;
    MedianFinder() {
        int m = mx_heap.size();
        int n = mn_heap.size();
    }
   
    void addNum(int num) {
        if(mx_heap.size()==0 ||mx_heap.top()>num)
        {
            mx_heap.push(num);
        }
        else 
        {
            mn_heap.push(num);
        }
        if(mx_heap.size()>mn_heap.size()+1)
        {
            mn_heap.push(mx_heap.top());
            mx_heap.pop();
        }
        else if(mn_heap.size()>mx_heap.size()+1)
        {
            mx_heap.push(mn_heap.top());
            mn_heap.pop();
        }
    }
    
    double findMedian() {
        if(mx_heap.size()>mn_heap.size())
        {
            return mx_heap.top();
        }
        else if(mn_heap.size()>mx_heap.size())
        {
            return mn_heap.top();
        }
        else
        {
            return (double)(1.00000*(mn_heap.top()+mx_heap.top())/2);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */