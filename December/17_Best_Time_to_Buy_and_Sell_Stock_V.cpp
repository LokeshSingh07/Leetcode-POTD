// 3573. Best Time to Buy and Sell Stock V

class Solution {
public:
    
    long long solve(vector<int> &prices, int k, int idx, int choice, vector<vector<vector<long long>>> &dp){
        if(idx >= prices.size()){
            if(choice == 0) return 0;
            return INT_MIN;
        }

        if(dp[idx][k][choice] != -1) return dp[idx][k][choice];

        long long notTake = solve(prices, k, idx+1, choice, dp);
        long long take = INT_MIN;
        if(k > 0){
            if(choice == 0){
                // buy and short sell
                take = max(-prices[idx] + solve(prices, k, idx+1, 1, dp), prices[idx] + solve(prices, k, idx+1, 2, dp));
            }
            else if(choice == 1){
                // sell
                take = prices[idx] + solve(prices, k-1, idx+1, 0, dp);
            }
            else{
                // short buy
                take = -prices[idx] + solve(prices, k-1, idx+1, 0, dp);
            }
        }

        return dp[idx][k][choice] = max(take, notTake);
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(k+1, vector<long long>(3, -1)));

        return solve(prices, k, 0, 0, dp);
    }
};