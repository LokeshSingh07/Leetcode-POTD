// 3459. Length of Longest V-Shaped Diagonal Segment

class Solution {
public:
    vector<vector<int>> dirs = {{1,1}, {1,-1}, {-1,-1}, {-1,1}};
    int m, n;

    int solve(vector<vector<int>> &grid, int i, int j, int d, bool canTurn, int val){
        int newX = i + dirs[d][0];
        int newY = j + dirs[d][1];

        if(newX<0 || newX>=m || newY<0 || newY>=n || grid[newX][newY] != val) return 0;


        int keepMoving = 1 + solve(grid, newX, newY, d, canTurn, val==2 ? 0 : 2);

        int turnAndMove = INT_MIN;
        if(canTurn){
            turnAndMove = 1 + solve(grid, newX, newY, (d+1)%4, false, val==2 ? 0 : 2);
        }

        return max(keepMoving, turnAndMove);
    }


    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int result = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    bool canTurn = true;
                    int val = 2;
                    for(int d=0; d<4; d++){
                        result = max(result, 1 + solve(grid, i, j, d, canTurn, val));
                    }
                }
            }
        }

        return result;
    }
};