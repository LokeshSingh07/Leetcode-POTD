// 1695. Maximum Erasure Value


class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int result = 0;
        int i=0, j=0;

        unordered_set<int> st;

        while(j<n){
            while(st.count(nums[j])){
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            sum +=  nums[j];
            st.insert(nums[j]);
            result = max(result, sum);
            
            j++;
        }

        return result;
    }
};