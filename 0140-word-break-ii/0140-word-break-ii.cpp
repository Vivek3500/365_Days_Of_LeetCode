class Solution {
public:
    // Recursive helper function to find all possible word break combinations
    void help(string s, int i, set<string>& st, vector<string>& ans, string t) {
        // If we have reached the end of the string, add the current combination to the answer vector
        if(i == s.size()) {
            // Remove the leading space and add the current combination to the answer vector
            string tmp = t.substr(1);
            ans.push_back(tmp);
            return;
        }

        string tmp;
        // Iterate over all possible substrings starting from the current index 'i'
        for(int j = i; j < s.size(); j++) {
            tmp += s[j];  // Append the current character to the temporary substring

            // If the current substring is a valid word in the word dictionary 'st'
            if(st.find(tmp) != st.end()) {
                // Call the 'help' function recursively for the remaining part of the string
                help(s, j + 1, st, ans, t + " " + tmp);
            }
        }

        return;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        // Insert all words in the dictionary to the set 'st'
        for(int i = 0; i < wordDict.size(); i++) {
            st.insert(wordDict[i]);
        }
        vector<string> ans;
        // Call the recursive 'help' function to find all possible word break combinations
        help(s, 0, st, ans, "");

        return ans;  // Return the vector of all possible word break combinations
    }
};