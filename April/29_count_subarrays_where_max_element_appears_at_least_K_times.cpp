// 2962. Count Subarrays Where Max Element Appears at Least K Times

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxE  = *max_element(begin(nums), end(nums));
        int n = nums.size();
        int i=0, j=0;
        int count = 0;
        long long result = 0;

        while(j<n){
            if(nums[j] == maxE){
                count++;
            }

            while(count == k){
                if(nums[i] == maxE){
                    count--;
                }
                i++;
            }

            result += i;
            
            j++;
        }

        return result;
    }
};