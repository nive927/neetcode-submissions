class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> ans;

        for(auto s: strs) {

            vector<int> count(26, 0);

            for(auto ch: s) {
                count[ch - 'a']++;
            }

            string key = to_string(count[0]);
            for (int i=1; i<26; i++) {
                key += "#" + to_string(count[i]);
            }

            anagrams[key].push_back(s);
        }

        for(auto p: anagrams) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
