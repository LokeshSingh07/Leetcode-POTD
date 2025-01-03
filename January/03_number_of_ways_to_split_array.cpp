// 2270. Number of Ways to Split Array

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n);
        int count = 0;

        // calculate prefix sum
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }


        for(int i=0; i<n-1; i++){
            long long leftSum = prefixSum[i];
            long long rightSum = prefixSum[n-1] - prefixSum[i];

            if(leftSum >= rightSum) count++;
        }

        return count;
    }
};