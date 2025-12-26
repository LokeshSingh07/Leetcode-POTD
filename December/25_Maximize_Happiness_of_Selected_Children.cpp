// 3075. Maximize Happiness of Selected Children

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(begin(happiness), end(happiness), greater<int>());

        long long result = 0;
        int idx = 0;
        while(k--){
            result += max(happiness[idx] - idx, 0);
            idx++; 
        }
        
        return result;
    }
};