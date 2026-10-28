class Solution {
public:
    bool isAnagram(string s, string t) {

        // if their length doesn't match,
        // they are obviously not anagrams 
        if(s.size() != t.size()) return false;
        
        unordered_map<char,int> counter;
        
        for(int i = 0; i < s.size(); i++){
            // NOTE: you don't have to set the initial
            // count to 0
            counter[s[i]]++;
        }
        
        for(int i = 0; i < t.size(); i++){
            // if t contains a letter not in the map - then they are not anagrams
            if(!counter.count(t[i])) return false;
            // reduce the count if seen in t
            counter[t[i]]--;
            // if there are more characters in t than in s
            // then the count will become -ve
            // which indicates it is not an anagram
            if(counter[t[i]] < 0) return false;
        }

        // if loop completes, then s and t are anagrams
        return true;
        
    }
};
