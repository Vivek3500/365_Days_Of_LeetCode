class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        for (int x = 1; x <= nums.size(); ++x) {
            int count = 0;
            for (int num : nums) {
                if (num >= x) {
                    ++count;
                }
            }
            if (count == x) {
                return x;
            }
        }
        return -1;
    }
};