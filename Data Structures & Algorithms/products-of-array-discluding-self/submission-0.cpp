class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // NOTE: if you don't initialize the arrays,
        // you will run into segmentation fault!!!!!

        // Writing down this helps you formulate the
        // OPTIMAL solution to reduce space complexity
        // You just don't build suffix
        // Build prefix first directly in ans
        // use a var postfix to directly multiply into ans!
        // see Solution or Editorial

        // vars
        vector<int> prefix (nums.size());
        vector<int> suffix(nums.size());
        vector<int> ans(nums.size());

        prefix[0] = 1;
        // construct the prefix prods
        for(int i=1; i<nums.size(); i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }
 
        suffix[nums.size() - 1] = 1;
        // construct the suffix prods
        for(int i=nums.size() - 2; i>=0; i--) {
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        // find the res
        for(int i=0; i<nums.size(); i++) {
            ans[i] = prefix[i] * suffix[i];
        }

        // return the ans
        return ans;

    }
};
