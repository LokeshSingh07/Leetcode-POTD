// 2560. House Robber IV

class Solution {
public:
    bool canPossible(vector<int> &nums, int k, int mid){
        int house = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= mid){
                house++;
                i++;
            }
        }

        return house >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int n =nums.size();
        int s = *min_element(begin(nums), end(nums));
        int e = *max_element(begin(nums), end(nums));
        int result = 0;

        while(s <= e){
            int mid = s+(e-s)/2;
            if(canPossible(nums, k, mid)){
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