class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // vars
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;

        vector<int> ans;

        unordered_map<int, int> counter;

        // create a counter for the frequency
        for(auto num: nums) {
            counter[num] += 1;
        }


        // iterate through the counter and push into the pq
        // ele: pair<count, item>
         for (auto numPair : counter) {
            minheap.push(make_pair(numPair.second, numPair.first));

            // need to min q - pop out elements when size of pq exceeds k
            if (minheap.size() > k) {
                minheap.pop();
            }
        }

        // construct the solution vector<int>
        for(int i=0; i<k; i++) {
            int top = minheap.top().second;
            ans.push_back(top);
            minheap.pop();
        }

        // return
        return ans;
        
        
    }

};

