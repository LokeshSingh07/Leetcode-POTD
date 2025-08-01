// 2411. Smallest Subarrays With Maximum Bitwise OR

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> setbitIdx(32, -1);
        vector<int> result(n);

        for(int i=n-1; i>=0; i--){
            int endIdx = i;
            for(int j=0; j<32; j++){
                // kth bit is not set
                if(!(nums[i] & (1<<j))){
                    if(setbitIdx[j] != -1)
                        endIdx = max(endIdx, setbitIdx[j]);
                }
                else{
                    setbitIdx[j] = i;
                }
            }

            result[i] = endIdx - i + 1; 
        }

        return result;
    }
};