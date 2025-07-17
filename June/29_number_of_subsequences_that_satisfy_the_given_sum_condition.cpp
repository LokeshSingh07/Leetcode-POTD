// 1498. Number of Subsequences That Satisfy the Given Sum Condition

class Solution {
public:
    int MOD = 1e9+7;
    int power(int a, int b){
        if(b==0) return 1;

        int half = power(a, b/2);
        int result = (1LL * half * half) % MOD;
        if(b&1){
            result = (1LL * result * a) % MOD; 
        }

        return result;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;
        int i=0, j=n-1;

        sort(begin(nums), end(nums));

        while(i<=j){
            if(nums[i]+nums[j] <= target){
                result = (result%MOD + power(2, j-i)%MOD)%MOD;
                i++;
            }else{
                j--;
            }
        }

        return result;
    }
};