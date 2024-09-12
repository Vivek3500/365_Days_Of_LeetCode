class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create a vector to mark which characters are allowed
        vector<bool> isAllowed(26, false);

        // Mark all characters in 'allowed' as true in the isAllowed vector
        for (int i = 0; i < allowed.length(); i++) {
            isAllowed[allowed[i] - 'a'] = true;
        }

        int consistentCount = 0;

        // Iterate through each word in the words array
        for (string& word : words) {
            bool isConsistent = true;

            // Check each character of the current word
            for (int i = 0; i < word.length(); i++) {
                // If any character is not allowed, mark as inconsistent and
                // break
                if (!isAllowed[word[i] - 'a']) {
                    isConsistent = false;
                    break;
                }
            }

            // If the word is consistent, increment the count
            if (isConsistent) {
                consistentCount++;
            }
        }

        return consistentCount;
    }
};