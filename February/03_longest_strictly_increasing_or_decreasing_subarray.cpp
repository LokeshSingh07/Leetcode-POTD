// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray

class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length;
        int maxLen = 0;

        for(int i=0; i<n; i++){
            int incLen=1, decLen=1;
            int j;
            for(j=i+1; j<n; j++){
                // strictly inreasing
                if(nums[j] > nums[j-1]) incLen++;
                else break;
            }

            for(j=i+1; j<n; j++){
                // strictly inreasing
                if(nums[j] < nums[j-1]) decLen++;
                else break;
            }

            maxLen = Math.max(maxLen, Math.max(incLen, decLen));
        }

        return maxLen;
    }
}