// 1800. Maximum Ascending Subarray Sum

class Solution {
    public int maxAscendingSum(int[] nums) {
        int n = nums.length;
        int maxSum = 0;

        for(int i=0; i<n; i++){
            int sum = nums[i];
            int j=i+1;
            while(j<n && nums[j-1] < nums[j]) sum += nums[j++];
            maxSum = Math.max(maxSum, sum);
        }

        return maxSum;
    }
}