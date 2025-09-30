// 611. Valid Triangle Number

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        if(n < 3) return 0;
        sort(begin(nums), end(nums));

        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                int sum = nums[i]+nums[j];
                int k =  upper_bound(begin(nums)+j+1, end(nums), sum-1) - begin(nums);
                count += (k-j-1);
            }
        }

        return count;
    }
};