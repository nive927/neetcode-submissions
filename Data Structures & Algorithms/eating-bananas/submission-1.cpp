class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int k;
        int ans = r;

        while(l <= r) {

            k = l + (r-l) / 2;

            long long duration = 0;
            for(int i=0; i<piles.size(); i++) {

                duration += ceil(static_cast<double>(piles[i]) / k);

            }

            if (duration <= h) {
                ans = k;
                r = k-1;
            } else {
                l = k+1;
            }

        }

        return ans;

        
    }
};
