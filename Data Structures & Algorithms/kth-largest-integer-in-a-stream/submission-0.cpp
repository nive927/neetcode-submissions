class KthLargest {
public:
    int maxSize;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    KthLargest(int k, vector<int>& nums) {
        
        maxSize = k;

        for(auto n: nums) {
            minHeap.push(n);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
    }
    
    int add(int val) {

        minHeap.push(val);
        if(minHeap.size() > maxSize) {
            minHeap.pop();
        }

        return minHeap.top();
        
    }
};
