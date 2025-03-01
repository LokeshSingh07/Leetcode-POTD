// 1749. Maximum Absolute Sum of Any Subarray

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefixSum = 0;
        int maxiAbsSum=0;
        int minPreSum=INT_MAX, maxPreSum=INT_MIN;

        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];

            minPreSum = min(minPreSum, prefixSum);
            maxPreSum = max(maxPreSum, prefixSum);

            if(prefixSum >= 0){
                maxiAbsSum = max(maxiAbsSum, max(prefixSum, prefixSum-minPreSum));
            }
            else{
                maxiAbsSum = max(maxiAbsSum, max(abs(prefixSum), abs(prefixSum-maxPreSum)));
            }
        }


        return maxiAbsSum;
    }
};