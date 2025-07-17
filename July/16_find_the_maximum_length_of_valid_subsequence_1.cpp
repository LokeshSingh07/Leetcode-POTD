// 3201. Find the Maximum Length of Valid Subsequence I

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int oddCnt=0, evenCnt=0;
        int alternate = 0;

        for(int i=0; i<n; i++){
            if(nums[i]&1) oddCnt++;
            else evenCnt++;
        }

        int parity = nums[0]&1;
        for(int i=1; i<n; i++){
            int currParity = nums[i]&1;
            if(currParity != parity){
                alternate++;
                parity = currParity;
            }
        }

        return max({evenCnt, oddCnt, alternate+1});
    }
};