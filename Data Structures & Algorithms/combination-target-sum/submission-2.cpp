class Solution {
    public:
    
        vector<vector<int>> ans;
    
        void backtrack(int start, int total, vector<int> curr, vector<int> nums, int target) {
    
            if(total == target) {
                ans.push_back(curr);
                return;
            }

            if(total > target) {
                return;
            }
    
            for(int i=start; i<nums.size(); i++) {
    
                total += nums[i];    
                curr.push_back(nums[i]);
                backtrack(i, total, curr, nums, target);
                total -= nums[i];
                curr.pop_back();
    
            }
    
        }
    
    
        vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    
            vector<int> curr;
    
            sort(nums.begin(), nums.end());
            backtrack(0, 0, curr, nums, target);
    
            return ans;       
            
        }
    };
    

// class Solution {
//     public:
//         vector<vector<int>> res;
    
//         void backtrack(int start, vector<int> cur, int total, vector<int>& nums, int target) {
//             if (total == target) {
//                 res.push_back(cur);
//                 return;
//             }
            
//             for (int i = start; i < nums.size(); i++) {
//                 if (total + nums[i] > target) {
//                     return;
//                 }
//                 cur.push_back(nums[i]);
//                 backtrack(i, cur, total + nums[i], nums, target);
//                 cur.pop_back();
//             }
//         }
    
//         vector<vector<int>> combinationSum(vector<int>& nums, int target) {
//             sort(nums.begin(), nums.end()); // NOTE!!!!
//             backtrack(0, {}, 0, nums, target);
//             return res;
//         }
//     };