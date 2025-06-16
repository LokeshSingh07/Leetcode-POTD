// 2616. Minimize the Maximum Difference of Pairs

class Solution {
public:
    bool isValid(vector<int> &nums, int p, int mid){
        int n = nums.size();
        int count = 0;
        int i=0;

        while(i<n-1){
            if(abs(nums[i] - nums[i+1]) <= mid){
                count++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(begin(nums), end(nums));

        int n = nums.size();
        int s = 0;
        int e = nums[n-1]-nums[0];
        int result=0;

        while(s<=e){
            int mid = s+(e-s)/2;
            if(isValid(nums, p, mid)){
                result = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
    
        return result;
    }
};