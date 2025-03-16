// 3356. Zero Array Transformation II

class Solution {
public:
    bool checkWithDiffArrTechn(vector<int> &nums, vector<vector<int>> &queries, int k){
        int n = nums.size();
        vector<int> diff(n,0);

        // setp1: diff[l]+=x 7 diff[r+1]-=x
        for(int i=0; i<=k; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];

            diff[l] += x;
            if(r+1 < n) diff[r+1] -= x;
        }

        // step2: cumSum
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += diff[i];
            diff[i] = sum;

            if(nums[i] - diff[i] > 0) return false;
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        auto lambda = [](int x){
            return x==0;
        };

        if(all_of(begin(nums), end(nums), lambda)) return 0;

        // check for each query
        int s=0;
        int e=q-1;
        int result = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(checkWithDiffArrTechn(nums, queries, mid)){
                result = mid+1;
                e = mid-1;;
            }
            else{
                s=mid+1;
            }
        }

        return result;
    }
};