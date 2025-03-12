// 2529. Maximum Count of Positive Integer and Negative Integer

class Solution {
public:
    void findPosIdx(vector<int> &nums, int &posIdx){
        int n = nums.size();
        int s=0, e=n-1;
        int mid;

        while(s<=e){
            mid = s + (e-s)/2;
            
            if(nums[mid] > 0){
                posIdx = mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }        
    }

    void findNegIdx(vector<int> &nums, int &negIdx){
        int n = nums.size();
        int s=0, e=n-1;
        int mid;

        while(s<=e){
            mid = s + (e-s)/2;
            
            if(nums[mid] < 0){
                negIdx = mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
    }

    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int posIdx=-1, negIdx=-1;
        
        findPosIdx(nums, posIdx);
        findNegIdx(nums, negIdx);

        return max((negIdx != -1 ? negIdx+1 : 0), (posIdx != -1 ? n-posIdx : 0));
    }
};