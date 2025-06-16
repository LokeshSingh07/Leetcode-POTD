// 3355. Zero Array Transformation I

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffArr(n, 0);

        // create diff array
        for(auto q: queries){
            int s = q[0];
            int e = q[1];

            diffArr[s] += 1;
            if(e+1 < n){
                diffArr[e+1] -= 1;
            }
        }


        // compute cumulative sum
        vector<int> cumSum(n, 0);
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += diffArr[i];
            cumSum[i] = sum;
        }


        for(int i=0; i<n; i++){
            if(cumSum[i] < nums[i]) return false;
        }

        return true;
    }
};