// 2294. Partition Array Such That Maximum Difference Is K

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int result = 1;
        int prev = nums[0];

        for(int i=0; i<n; i++){
            if(nums[i] - prev <= k) continue;
            result++;
            prev = nums[i];
        }

        return result;
    }
};