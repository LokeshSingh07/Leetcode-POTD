// 3423. Maximum Difference Between Adjacent Elements in a Circular Array

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int diff = INT_MIN;

        for(int i=0; i<n; i++){
            diff = max(diff, abs(nums[i] - nums[(i+1)%n]));
        }

        return diff;
    }
};