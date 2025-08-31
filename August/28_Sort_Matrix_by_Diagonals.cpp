// 3446. Sort Matrix by Diagonals

class Solution {
public:
    void sortDiagonal(int r, int c, vector<vector<int>> &grid, bool asc){
        int i = r;
        int j = c;
        vector<int> temp;
        int n = grid.size();

        while(i<n && j<n){
            temp.push_back(grid[i][j]);
            i++;
            j++;
        }

        if(asc) sort(begin(temp), end(temp));
        else sort(rbegin(temp), rend(temp));

        i = r;
        j = c;
        for(auto &val: temp){
            grid[i][j] = val;
            i++; j++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for(int r=0; r<n; r++){
            sortDiagonal(r, 0, grid, false);
        }

        for(int c=1; c<n; c++){
            sortDiagonal(0, c, grid, true);
        }

        return grid;
    }
};