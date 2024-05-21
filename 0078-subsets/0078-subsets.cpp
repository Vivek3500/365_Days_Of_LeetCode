class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        output.push_back({});
        for (int num : nums) {
            vector<vector<int>> newSubsets;
            for (vector<int> curr : output) {
                vector<int> temp = curr;
                temp.push_back(num);
                newSubsets.push_back(temp);
            }
            for (vector<int> curr : newSubsets) {
                output.push_back(curr);
            }
        }
        return output;
    }
};