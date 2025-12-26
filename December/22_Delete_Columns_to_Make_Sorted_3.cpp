// 960. Delete Columns to Make Sorted III

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        vector<int> dp(n, 1);
        int LIS = 1;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                bool flag = true;
                for(int k=0; k<m; k++){
                    if(strs[k][j] > strs[k][i]){
                        flag = false;
                        break;
                    }
                }

                if(flag) dp[i] = max(dp[i], dp[j]+1);
            }

            LIS = max(LIS, dp[i]);
        }


        return n - LIS;
    }
};