// 3652. Best Time to Buy and Sell Stock using Strategy

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> prefixSum(n, 0);
        vector<long long> prefixPrices(n, 0);

        for(int i=0; i<n; i++){
            prefixSum[i] = (i>0 ? prefixSum[i-1] : 0) + (prices[i] * strategy[i]);
            prefixPrices[i] = (i>0 ? prefixPrices[i-1] : 0) + prices[i];
        }

        long long result = prefixSum[n-1];
        for(int i=0; i<n-k+1; i++){
            long long leftSum = i>0 ? prefixSum[i-1] : 0;
            long long rightSum = prefixSum[n-1] - prefixSum[i+k-1];
            long long changeSum = prefixPrices[i+k-1] - prefixPrices[i-1+(k/2)];

            result = max(result, leftSum + changeSum + rightSum);
        }

        return result;
    }
};