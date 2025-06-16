// 3068. Find the Maximum Sum of Node Values

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        int count = 0;
        int minLoss = INT_MAX;

        for(auto num: nums){
            if((num^k) > num){
                count++;
                sum += num^k;
            }
            else{
                sum += num;
            }

            minLoss = min(minLoss, abs((num^k) - num));
        }

        if(count & 1) return sum - minLoss;
        return sum; 
    }
};