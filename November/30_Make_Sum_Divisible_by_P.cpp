// 1590. Make Sum Divisible by P

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int sum = 0;

        for(auto num: nums){
            sum = (sum + num) % p;
        }

        int target = sum % p;
        if(target == 0) return 0;

        int result = n;
        int curr = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;

        for(int j=0; j<n; j++){
            curr = (curr + nums[j]) % p;
            int rem = (curr - target + p) % p;
            if(mp.find(rem) != mp.end()){
                result = min(result, j - mp[rem]);
            }
            mp[curr] = j;
        }

        return result == n ? -1 : result;
    }
};