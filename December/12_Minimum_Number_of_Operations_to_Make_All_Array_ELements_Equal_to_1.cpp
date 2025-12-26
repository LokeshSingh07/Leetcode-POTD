// 2654. Minimum Number of Operations to Make All Array Elements Equal to 1

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int count = 0;
        for(int i=0; i<n; i++){ 
            if(nums[i] == 1) count++;
        }
        if(count > 0){
            return n-count;
        }

        int opn = INT_MAX;
        for(int i=0; i<n; i++){
            int GCD = nums[i];
            for(int j=i+1; j<n; j++){
                GCD = gcd(GCD, nums[j]);
                if(GCD == 1){
                    opn = min(opn, j-i);
                    break;
                }
            }
        }

        if(opn == INT_MAX) return -1;

        return opn + (n-1);
    }
};