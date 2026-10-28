class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(int start, int total, vector<int> curr, vector<int> candidates, int target) {

        if(total == target) {
            ans.push_back(curr);
            return;
        }

        if(total > target) {
            return;
        }

        for(int i=start; i<candidates.size(); i++) {

            total += candidates[i];
            curr.push_back(candidates[i]);

            backtrack(i+1, total, curr, candidates, target);

            curr.pop_back();
            total -= candidates[i];

            while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
                i++;
            }

        }


    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        ans.clear();
        vector<int> curr;

        sort(candidates.begin(), candidates.end());
        backtrack(0, 0, curr, candidates, target);

        return ans;

    }
};
