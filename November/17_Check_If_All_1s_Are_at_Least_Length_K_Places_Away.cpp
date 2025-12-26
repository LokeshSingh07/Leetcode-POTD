// 1437. Check If All 1's Are at Least Length K Places Away

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int i = -1, j = 0;

        while(j<n){
            if(nums[j] == 1){
                if(i != -1 && j-i <= k){
                    return false;
                }

                i = j;
            }

            j++;
        }

        return true;;
    }
};