// 594. Longest Harmonious Subsequence

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int result=0, j=0;
        sort(begin(nums), end(nums));


        for(int i=0; i<n; i++){
            while(nums[i]-nums[j] > 1) j++;
                
            if(nums[i] - nums[j] == 1){
                result = max(result, i-j+1);
            }
        }

        return result;
    }
};