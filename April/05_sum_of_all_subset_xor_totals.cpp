// 1863. Sum of All Subset XOR Totals

// Method 1: Recursion
class Solution {
public:
    vector<vector<int>> vec;
    void generateAllSubset(vector<int> &nums, int i, vector<int> &temp){
        if(i >= nums.size()){
            return;
        }

        generateAllSubset(nums, i+1, temp);

        temp.push_back(nums[i]);
        vec.push_back(temp);
        generateAllSubset(nums, i+1, temp);
        temp.pop_back();
    }

    int subsetXORSum(vector<int>& nums) {
        vector<int> temp;

        generateAllSubset(nums, 0, temp);

        int ans = 0;
        for(auto v: vec){
            int XOR = 0; 
            for(int j=0; j<v.size(); j++){
                XOR ^= v[j];
            }
            ans += XOR;
        }

        return ans;
    }
};



// Method 2: Bit manipulation
