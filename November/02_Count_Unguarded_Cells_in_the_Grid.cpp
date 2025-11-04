// 2257. Count Unguarded Cells in the Grid

class Solution {
public:
    void solve(vector<vector<int>> &mat, int &x, int &y){
        int m = mat.size();
        int n = mat[0].size();

        // move in the 4 direction
        for(int j=y+1; j<n; j++){
            if(mat[x][j] == 1 || mat[x][j] == 2) break;
            mat[x][j] = 3;
        }

        for(int j=y-1; j>=0; j--){
            if(mat[x][j] == 1 || mat[x][j] == 2) break;
            mat[x][j] = 3;
        }

        for(int i=x+1; i<m; i++){
            if(mat[i][y] == 1 || mat[i][y] == 2) break;
            mat[i][y] = 3;
        }

        for(int i=x-1; i>=0; i--){
            if(mat[i][y] == 1 || mat[i][y] == 2) break;
            mat[i][y] = 3;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int space = 0;
        int wall = 1;
        int guard = 2;
        vector<vector<int>> mat(m, vector<int>(n,0));
        
        for(auto wall: walls){
            int x = wall[0];
            int y = wall[1];
            mat[x][y] = 1;
        }

        for(auto guard: guards){
            int x = guard[0];
            int y = guard[1];
            mat[x][y] = 2;
        }
        
        for(auto guard: guards){
            int x = guard[0];
            int y = guard[1];
            solve(mat, x, y);
        }

        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0) count++;
            }
        }

        return count;
    }
};