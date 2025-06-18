// 2966. Divide Array Into Arrays With Max Difference

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        vector<vector<int>> ans;
        for(int i=0; i<n-2; i+=3){
            if(nums[i+2] - nums[i] > k) return {};
            ans.push_back({nums[i], nums[i+1], nums[i+2]});
        }

        return ans;
    }
};