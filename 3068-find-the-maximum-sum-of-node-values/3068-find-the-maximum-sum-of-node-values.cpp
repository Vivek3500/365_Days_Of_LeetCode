class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<vector<long long>> memo(nums.size(), vector<long long>(2, -1));
        return maxSum(0, 1, nums, k, memo);
    }

private:
    long long maxSum(int index, int isEven, vector<int>& nums, int k, vector<vector<long long>>& memo) {
        if (index == nums.size()) return isEven ? 0 : INT_MIN;
        if (memo[index][isEven] != -1) return memo[index][isEven];
        
        long long noXorDone = nums[index] + maxSum(index + 1, isEven, nums, k, memo);
        long long xorDone = (nums[index] ^ k) + maxSum(index + 1, isEven ^ 1, nums, k, memo);

        return memo[index][isEven] = max(xorDone, noXorDone);
    }
};
