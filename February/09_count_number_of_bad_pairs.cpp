// 2364. Count Number of Bad Pairs

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long count=0;
        unordered_map<int,int> mp;
        vector<int> arr(n);
        arr[0] = nums[0];
        mp[arr[0]]++;

        for(int i=1; i<n; i++){
            arr[i] = nums[i] - i;
            int badPair = i;
            if(mp.find(arr[i]) != mp.end()){
                badPair = i - mp[arr[i]];
            }

            count += badPair;
            mp[arr[i]]++;
        }

        return count;
    }
};