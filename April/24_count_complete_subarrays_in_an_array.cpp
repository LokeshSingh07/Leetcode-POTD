// 2799. Count Complete Subarrays in an Array

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int distinctCount = 0;
        
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        distinctCount = mp.size();

        int completeSubarrayCount = 0;
        for(int i=0; i<=n-distinctCount; i++){
            unordered_map<int,int> mp2;
            int j=i;
            while(j<n && mp2.size()<=distinctCount){
                mp2[nums[j]]++;
                if(mp2.size() == distinctCount){
                    completeSubarrayCount++;
                }
                j++;
            }
        }


        return completeSubarrayCount;
    }
};