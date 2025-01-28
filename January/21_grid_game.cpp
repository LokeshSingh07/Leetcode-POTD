// 2017. Grid Game

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long firstRowRemSum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long secondRowRemSum = 0;
        long long minimizedRobo2 = LLONG_MAX;

        for(int i=0; i<n; i++){
            firstRowRemSum -= grid[0][i];
            if(i>0) secondRowRemSum += grid[1][i-1];
            long long temp = max(firstRowRemSum, secondRowRemSum);

            minimizedRobo2 = min(minimizedRobo2, temp); 
        }

        return minimizedRobo2;
    }
};