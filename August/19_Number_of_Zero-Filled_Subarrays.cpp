// 2348. Number of Zero-Filled Subarrays

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        int i=0, j=0;

        while(j<n){
            if(!nums[j]){
                count += (j-i+1);
                j++;
            }else{
                j++;
                i=j;
            }
        }

        return count;
    }
};