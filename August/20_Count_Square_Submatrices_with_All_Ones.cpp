// 1277. Count Square Submatrices with All Ones

class Solution {
public:
    int t[301][301];
    int m, n;
    
    int solve(vector<vector<int>> &matrix, int i, int j){
        if(i>=m || j>=n || !matrix[i][j]) return 0;

        if(t[i][j] != -1) return t[i][j];

        int right = 1 + solve(matrix, i, j+1);
        int diagonal = 1 + solve(matrix, i+1, j+1);
        int down = 1 + solve(matrix, i+1, j);
        return t[i][j] = min(diagonal, min(right, down));
    }

    int countSquares(vector<vector<int>>& matrix) {
        memset(t, -1, sizeof(t));
        m = matrix.size();
        n = matrix[0].size();
        int result = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]){
                    result += solve(matrix, i, j);
                }
            }
        }

        return result;
    }
};