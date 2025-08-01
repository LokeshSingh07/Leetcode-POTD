// 2419. Longest Subarray With Maximum Bitwise AND

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxAND = *max_element(begin(nums), end(nums));

        int len=0, maxLen=0;
        for(int i=0; i<n; i++){
            if(nums[i] == maxAND){
                len++;
                maxLen = max(maxLen, len);
            }
            else{
                len=0;    
            }
        }

        return maxLen;
    }
};