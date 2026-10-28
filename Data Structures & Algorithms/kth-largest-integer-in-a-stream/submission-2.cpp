class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kth;

    KthLargest(int k, vector<int>& nums) {

        kth = k;

        for(int i=0; i<nums.size(); i++) {
            minHeap.push(nums[i]);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > kth) {
            minHeap.pop();
        }

        return minHeap.top();

    }
};
