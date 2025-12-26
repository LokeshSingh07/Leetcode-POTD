// 3381. Maximum Subarray Sum With Length Divisible by K

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefixSum = 0;
        long long maxSum = LLONG_MIN;
        vector<long long> kSum(k, LLONG_MAX/2);
        kSum[k-1] = 0;

        for(int i=0; i<n; i++){
            prefixSum += nums[i];

            maxSum = max(maxSum, prefixSum - kSum[i%k]);
            kSum[i % k] = min(kSum[i%k], prefixSum);
        }

        return maxSum;
    }
};