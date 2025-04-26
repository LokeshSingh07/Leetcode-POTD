// 2444. Count Subarrays With Fixed Bounds

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int minKPos = -1;
        int maxKPos = -1;
        int culpritIndex = -1;
        long long result = 0;

        for(int i=0; i<n; i++){
            if(nums[i]<minK || nums[i]>maxK){
                culpritIndex = i;
            }
            
            if(nums[i] == minK) minKPos = i;
            if(nums[i] == maxK) maxKPos = i;

            int temp = min(minKPos, maxKPos);
            result += (temp - culpritIndex) <= 0 ? 0 : (temp - culpritIndex);
        }

        return result;
    }
};