// 2401. Longest Nice Subarray

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int mask = 0;
        int result = 0;

        for(int i=0; i<n; i++){
            mask = 0;
            for(int j=i; j<n; j++){
                if((mask & nums[j]) != 0) break;
                mask |= nums[j];
                result = max(result, j-i+1);
            }
        }

        return result;
    }
};