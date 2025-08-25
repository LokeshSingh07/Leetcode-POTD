// 1504. Count Submatrices With All Ones

class Solution {
public:
    int calculate(vector<int> &nums){
        int count = 0;
        int subarrCnt = 0;
        for(auto num: nums){
            if(num == 0) count = 0;
            else count++;
            subarrCnt += count;
        }
        return subarrCnt;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int result = 0;

        for(int sr=0; sr<m; sr++){
            vector<int> vec(n, 1);
            for(int er=sr; er<m; er++){
                for(int col=0; col<n; col++){
                    vec[col] = vec[col] & mat[er][col];
                }
                result += calculate(vec);
            }
        }

        return result;
    }
};