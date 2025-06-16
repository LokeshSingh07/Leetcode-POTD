// 2016. Maximum Difference Between Increasing Elements


// Method 1: O(n^2)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxiDiff = -1;

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(nums[j] > nums[i])
                    maxiDiff= max(maxiDiff, nums[j]- nums[i]);
            }
        }

        return maxiDiff;
    }
};


// Method 2: O(n)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int miniPre = nums[0];
        int maxDiff = -1;

        for(int i=1; i<n; i++){
            if(miniPre >= nums[i]){
                miniPre = nums[i];
            }
            else{
                maxDiff = max(maxDiff, nums[i]-miniPre);
            }
        }

        return maxDiff;
    }
};