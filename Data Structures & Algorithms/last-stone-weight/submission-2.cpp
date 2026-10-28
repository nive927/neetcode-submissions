class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> minHeap;
        int x, y;

        for(int i=0; i<stones.size(); i++) {
            minHeap.push(stones[i]);
        }

        while (minHeap.size() > 1) {
            x = minHeap.top();
            minHeap.pop();
            y = minHeap.top();
            minHeap.pop();

            if (abs(x-y) > 0) {
                minHeap.push(abs(x-y));
            }
        }

       return minHeap.size() == 0 ? 0 :  minHeap.top();
        
    }
};
