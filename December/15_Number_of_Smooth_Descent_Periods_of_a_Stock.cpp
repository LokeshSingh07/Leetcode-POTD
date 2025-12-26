// 2110. Number of Smooth Descent Periods of a Stock

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long result = 1;
        long long curr = 1;

        for(int i=1; i<n; i++){
            if(prices[i] == prices[i-1] - 1) curr++;
            else curr = 1;

            result += curr;
        }

        return result;
    }
};