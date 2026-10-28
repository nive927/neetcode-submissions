class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int single = 0; // any number XOR 0 is the same number

        for(auto n: nums) {

            single = single ^ n;
        }

        return single;
        
    }
};
