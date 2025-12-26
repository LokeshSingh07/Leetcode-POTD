// 2154. Keep Multiplying Found Values by Two

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(begin(nums), end(nums));

        for(auto num: nums){
            if(num == original){
                original *= 2;
            }
        }

        return original;
    }
};