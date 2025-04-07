// 416. Partition Equal Subset Sum

class Solution {
public:
    bool solve(vector<int> &nums, int i, int target, vector<vector<int>> &dp){
        if(i >= nums.size() || target < 0){
            return false;
        }
        if(target == 0) return true;

        if(dp[i][target] != -1) return dp[i][target];

        // take & notTake
        int take = solve(nums, i+1, target-nums[i], dp);
        int notTake = solve(nums, i+1, target, dp);

        return dp[i][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);
        if(sum & 1) return false;
        int target = sum/2;

        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(nums, 0, target, dp);
    }
};