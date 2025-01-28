// 1267. Count Servers that Communicate

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int serverCnt = 0;
        vector<int> rowCnt(m,0), colCnt(n,0);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }


        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] && (rowCnt[i]>1 || colCnt[j]>1)){
                    serverCnt++;
                }    
            }
        }

        return serverCnt;
    }
};