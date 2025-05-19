// 1931. Painting a Grid With Three Different Colors

class Solution {
public:
    vector<vector<int>> dp;
    vector<string> columnStates;
    const int MOD = 1e9+7;

    void generateColumnStates(string currCol, int rowsRem, char prevColor){
        if(rowsRem == 0){
            columnStates.push_back(currCol);
            return;
        }

        for(char color: {'R', 'G', 'B'}){
            if(color == prevColor) continue;

            generateColumnStates(currCol + color, rowsRem-1, color);
        }
    }
 
    int solve(int remCols, int prevColIdx, int m){
        if(remCols == 0) return 1;

        if(dp[remCols][prevColIdx] != -1){
            return dp[remCols][prevColIdx];
        }

        int totalWays = 0;
        string prevCol = columnStates[prevColIdx];

        for(int i=0; i<columnStates.size(); i++){
            string nextCol = columnStates[i];
            bool valid = true;

            for(int r=0; r<m; r++){
                if(prevCol[r] == nextCol[r]){
                    valid = false;
                    break;
                }
            }
            
            if(valid){
                totalWays = (totalWays + solve(remCols-1, i, m)) % MOD;
            }
        }

        return dp[remCols][prevColIdx] = totalWays;
    }

    int colorTheGrid(int m, int n) {
        columnStates.clear();
        generateColumnStates("", m, '#');

        int numColPattern = columnStates.size();
        dp.assign(n, vector<int>(numColPattern, -1));

        int result = 0;
        for(int i=0; i<numColPattern; i++){
            result = (result + solve(n-1, i, m)) % MOD;
        }

        return result;
    }
};