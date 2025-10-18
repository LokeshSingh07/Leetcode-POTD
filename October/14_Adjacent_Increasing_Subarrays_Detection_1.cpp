// 3349. Adjacent Increasing Subarrays Detection I

// Approach-1: 
class Solution {
public:
    bool isIncreasing(vector<int> &nums, int s, int e){
        int n = nums.size();
        for(int i=s+1; i<e; i++){
            if(nums[i-1] >= nums[i]) return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i=0; i<=n-2*k; i++){
            int first = isIncreasing(nums, i, i+k);
            int second = isIncreasing(nums, i+k, i+k+k);
            if(first && second) return true;
        }

        return false;
    }
};


// Approach-2: 
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int prevRun = 0;
        int currRun = 1;

        for(int i=1; i<n; i++){
            if(nums[i-1] < nums[i]){
                currRun++;
            }
            else{
                prevRun = currRun;
                currRun = 1;
            }
        
            if(currRun >= 2*k) return true;
            if(min(prevRun, currRun) >= k) return true;
        }

        return false;
    }
};