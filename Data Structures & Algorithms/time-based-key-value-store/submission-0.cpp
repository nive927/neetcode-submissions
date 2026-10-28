class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> store;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {

        auto pairs = store[key];

        int l=0;
        int r=pairs.size()-1;
        string res = "";

        while(l<=r) {
            int mid = l+(r-l)/2;

            if(pairs[mid].first <= timestamp) {
                res = pairs[mid].second;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return res;
        
    }
};
