class Solution {
public:

    string encode(vector<string>& strs) {

        string encoded = "";

        for(auto s: strs) {
            encoded += to_string(s.size()) + "#" + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {

        vector<string> decoded;
    int i = 0;

    while (i < s.size()) {
        // Find the position of the delimiter '#'
        int delimiterPos = s.find('#', i);

        // Extract the length prefix
        int length = stoi(s.substr(i, delimiterPos - i));

        // Move the pointer to the start of the string
        i = delimiterPos + 1;

        // Extract the string of the given length
        decoded.push_back(s.substr(i, length));

        // Move the pointer to the next encoded string
        i += length;
    }

    return decoded;

    }
};
