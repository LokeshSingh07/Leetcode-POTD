// 368. Largest Divisible Subset

// Method 1: TLE
class Solution {
public:
    vector<int> result;
    void solve(vector<int> &nums, int i, vector<int> &temp){
        if(i>=nums.size()){
            if(temp.size() > result.size()) result = temp;
            return;
        }

        // take
        if(temp.empty() || nums[i] % temp.back() == 0){
            temp.push_back(nums[i]);
            solve(nums, i+1, temp);
            temp.pop_back();
        }

        // not take
        solve(nums, i+1, temp);
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));

        vector<int> temp;

        solve(nums, 0, temp);

        return result;
    }
};

// Method 2: Tabulation
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();

        vector<int> dp(n, 1), prev(n, -1);
        int maxI = 0;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    prev[i] = j;
                }
            }

            if(dp[i] > dp[maxI]){
                maxI = i;
            }
        }


        vector<int> result;
        while(maxI != -1){
            result.push_back(nums[maxI]);
            maxI = prev[maxI];
        }

        reverse(result.begin(),result.end());
        return result;
    }
};