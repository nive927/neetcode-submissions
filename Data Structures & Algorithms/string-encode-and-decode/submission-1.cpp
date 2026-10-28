class Solution {
public:

    string encode(vector<string>& strs) {

        string res = "";

        for(auto s: strs) {

            res += to_string(s.size()) + "#" + s;

        }

        return res;
        
    }

    vector<string> decode(string s) {

        vector<string> res;

        int i=0;
        while(i < s.size()) {
            int j=i;

            while(s[j] != '#') {
                j++;
            }

            // you need to find a substr because the length could be a 
            // > one-digit number: 99, 103, etc
            int len = stoi(s.substr(i, j-i));
            res.push_back(s.substr(j+1, len));
            i = j+1+len;
        }

        return res;

    }
};
