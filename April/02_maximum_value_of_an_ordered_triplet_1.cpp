// 2873. Maximum Value of an Ordered Triplet I

// Method 1: Brute force
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxVal = 0;

        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    maxVal = max(maxVal, (long long)(nums[i]-nums[j]) * nums[k]);
                }
            }
        }

        return maxVal;
    }
};


// Method 2: using precompute leftMax and rightMax of ith index
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        // precompute
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1], nums[i-1]);
        }
        for(int i=n-2; i>0; i--){
            right[i] = max(nums[i+1], right[i+1]);
        }

        long long maxValue = 0;
        for(int j=1; j<n-1; j++){
            maxValue = max(maxValue, (long long)(left[j]-nums[j])*right[j]);
        }

        return maxValue;
    }
};

