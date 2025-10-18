// 3186. Maximum Total Damage With Spell Casting


class Solution {
public:
    typedef long long ll;
    unordered_map<int, ll> mp;
    ll t[100001];
    int n;
    
    ll solve(vector<int> &nums, int i){
        if(i >= n) return 0;
        if(t[i] != -1) return t[i];

        ll skip = solve(nums, i+1);

        ll j = lower_bound(begin(nums)+i+1, end(nums), nums[i]+3) - begin(nums);
        ll take = nums[i] * mp[nums[i]] + solve(nums, j);

        return t[i] = max(take, skip);
    }

    long long maximumTotalDamage(vector<int>& power) {
        n = power.size();
        memset(t, -1, sizeof(t));

        for(auto p: power){
            mp[p]++;
        }

        sort(begin(power), end(power));

        return solve(power, 0);
    }
};