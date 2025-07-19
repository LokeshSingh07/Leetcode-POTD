// 3202. Find the Maximum Length of Valid Subsequence II


// LIS variant
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(k+1, vector<int>(n+1, 1));
        int result = 1;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int Mod = (nums[i]+nums[j])%k;
                dp[Mod][i] = max(1 + dp[Mod][j], dp[Mod][i]);
                result = max(result, dp[Mod][i]);
            }
        }

        return result;
    }
};