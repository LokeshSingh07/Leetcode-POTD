// 2874. Maximum Value of an Ordered Triplet II

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxVal = 0;
        long long maxi = INT_MIN;
        long long maxDiff = 0;

        for(int i=0; i<n; i++){
            maxVal = max(maxVal, (maxDiff*nums[i]));
            maxDiff = max(maxDiff, (maxi-nums[i]));
            maxi = max(maxi, (long long)nums[i]);
        }

        return maxVal;
    }
};