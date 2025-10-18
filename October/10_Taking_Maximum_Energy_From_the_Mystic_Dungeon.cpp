// 3147. Taking Maximum Energy From the Mystic Dungeon

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n);
        int result = INT_MIN;

        for(int i=n-1; i>=0; i--){
            if(i+k < n) dp[i] = energy[i] + dp[i+k];
            else dp[i] = energy[i];
            result = max(result, dp[i]);
        }

        return result;
    }
};