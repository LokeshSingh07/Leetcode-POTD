// 3375. Minimum Operations to Make Array Values Equal to K

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;

        for(auto &x: nums){
            if(x < k) return -1;
            if(x > k) st.insert(x);
        }

        return st.size();
    }
};