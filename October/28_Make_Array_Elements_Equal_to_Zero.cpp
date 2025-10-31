// 3354. Make Array Elements Equal to Zero

// Approach-1:
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefSum(n, 0);

        for(int i=0; i<n; i++){
            prefSum[i] = nums[i] + (i>0 ? prefSum[i-1] : 0);
        }

        int result = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                int leftSum = (i>0 ? prefSum[i-1] : 0);
                int rightSum = prefSum[n-1] - prefSum[i];
            
                if(leftSum == rightSum) result += 2;
                else if(abs(leftSum-rightSum) == 1) result += 1;
            }
        }

        return result;
    }
};


// Approach-2: 
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(begin(nums), end(nums), 0);

        int result = 0;
        int currSum = 0;
        for(int i=0; i<n; i++){
            currSum += nums[i];

            if(nums[i] == 0){
                int leftSum = currSum;
                int rightSum = totalSum - currSum;
            
                if(leftSum == rightSum) result += 2;
                else if(abs(leftSum-rightSum) == 1) result += 1;
            }
        }

        return result;
    }
};