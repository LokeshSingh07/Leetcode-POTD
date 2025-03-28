// 2780. Minimum Index of a Valid Split

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;

        for(int i=0; i<n; i++) mp2[nums[i]]++;

        for(int i=0; i<n; i++){
            int num = nums[i];
            mp1[num]++;
            mp2[num]--;
            int n1 = i+1;
            int n2 = n-1-i;
            if(mp1[num] >n1/2 && mp2[num] > n2/2) return i;
        }

        return -1;
    }
};