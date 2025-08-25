// 1493. Longest Subarray of 1's After Deleting One Element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        int zeroCount = 0;
        int i=0;

        for(int j=0; j<n; j++){
            if(nums[j] == 0) zeroCount++;

            while(zeroCount > 1){
                if(nums[i] == 0){
                    zeroCount--;
                }
                i++;
            }
            len = max(len, j-i);
        }

        return len;
    }
};