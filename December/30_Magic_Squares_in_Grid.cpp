// 840. Magic Squares In Grid

class Solution {
public:
    bool checkMagicSquare(vector<vector<int>> &grid, int x, int y){
        // early check 
        if(grid[x+1][y+1] != 5) return false;

        unordered_set<int> set;
        for(int i=x; i<x+3; i++){
            for(int j=y; j<y+3; j++){
                if(grid[i][j] < 1 || grid[i][j] > 9 || set.count(grid[i][j])) return false;
                set.insert(grid[i][j]);
            }
        }

        // check row sum and col sum
        int sum = grid[x][y] + grid[x][y+1] + grid[x][y+2];
        for(int i=0; i<3; i++){
            if(grid[x+i][y] + grid[x+i][y+1] + grid[x+i][y+2] != sum) return false;    
            if(grid[x][y+i] + grid[x+1][y+i] + grid[x+2][y+i] != sum) return false;
        }

        // diagonal and anti-diagonal
        if(grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2] != sum) return false;
        if(grid[x][y+2] + grid[x+1][y+1] + grid[x+2][y] != sum) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;

        for(int i=0; i<m-2; i++){
            for(int j=0; j<n-2; j++){
                if(checkMagicSquare(grid, i, j)){
                    count++;
                }
            }
        }
        
        return count;
    }
};