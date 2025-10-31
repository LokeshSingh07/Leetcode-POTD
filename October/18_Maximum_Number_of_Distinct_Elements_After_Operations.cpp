// 3397. Maximum Number of Distinct Elements After Operations

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int prev = INT_MIN;
        int count = 0;
        for(int i=0; i<n; i++){
            int minVal = nums[i] - k;
            if(prev < minVal){
                prev = minVal;
                count++;
            }
            else if(prev < nums[i]+k){
                prev = prev+1;
                count++;
            }
        }

        return count;
    }
};