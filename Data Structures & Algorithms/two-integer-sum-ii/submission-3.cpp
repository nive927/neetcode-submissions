class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int l = 0;
        int r = numbers.size() - 1;
        vector<int> res(2, 0);

        // index 1 != index 2
        while(l < r) {

            int sum = numbers[l] + numbers[r];

            if(sum < target) {
                l++;
            } else if(sum > target) {
                r--;
            } else if (sum == target) {
                res[0] = l+1;
                res[1] = r+1;
                break;
            }
        }

        return res;
        
    }
};
