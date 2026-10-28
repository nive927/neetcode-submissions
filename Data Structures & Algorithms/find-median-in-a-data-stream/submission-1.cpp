class MedianFinder {
public:

    priority_queue<int, vector<int>, less<int>> small; // maxHeap
    priority_queue<int, vector<int>, greater<int>> big; // minHeap

    MedianFinder() {
        // init
    }
    
    void addNum(int num) {

        small.push(num);

        if (!big.empty() && small.top() > big.top()) {
            big.push(small.top());
            small.pop();
        }
        if (small.size() > big.size() + 1) {
            big.push(small.top());
            small.pop();
        }
        if (big.size() > small.size() + 1) {
            small.push(big.top());
            big.pop();
        }
        
    }
    
    double findMedian() {

        if(small.size() > big.size()) {
            return small.top();   
        } else if (small.size() < big.size()) {
            return big.top();
        }

        return static_cast<double>((small.top() + big.top())) / 2;
        
    }
};

