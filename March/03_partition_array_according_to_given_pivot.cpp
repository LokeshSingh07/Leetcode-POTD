// 2161. Partition Array According to Given Pivot

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> temp;
        vector<int> ans;
        int i, count=0;

        for(i=0; i<n; i++){
            if(nums[i] < pivot){
                ans.push_back(nums[i]);
            }
            else{
                if(nums[i] == pivot){
                    count++;
                    continue;
                }
                temp.push_back(nums[i]);
            }
        }

        while(count--) ans.push_back(pivot);
        
        for(i=0; i<temp.size(); i++){
            ans.push_back(temp[i]);
        }

        return ans;
    }
};