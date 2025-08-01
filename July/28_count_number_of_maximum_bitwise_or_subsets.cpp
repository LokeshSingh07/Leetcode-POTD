// 2044. Count Number of Maximum Bitwise-OR Subsets

class Solution {
public:
    int solve(vector<int> &nums, int i, int &maxOR, int currOR){
        if(i >= nums.size()){
            if(maxOR == currOR) return 1;
            return 0;
        }

        int take = solve(nums, i+1, maxOR, currOR | nums[i]);
        int skip = solve(nums, i+1, maxOR, currOR);
        
        return take + skip;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0, currOR = 0;
        for(auto &n: nums){
            maxOR |= n;
        }

        return solve(nums, 0, maxOR, currOR);
    }
};