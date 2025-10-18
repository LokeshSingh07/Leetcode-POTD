// 417. Pacific Atlantic Water Flow

class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    int m, n;

    void dfs(vector<vector<int>> &heights, int i, int j, vector<vector<bool>> &visited){
        visited[i][j] = true;

        for(auto dir: dirs){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(i_>=0 && i_<m && j_>=0 && j_<n && !visited[i_][j_] && heights[i_][j_] >= heights[i][j]){
                dfs(heights, i_, j_, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // dfs for first & last col
        for(int i=0; i<m; i++){
            dfs(heights, i, 0, pacific);
            dfs(heights, i, n-1, atlantic);
        }

        // dfs for first & last row
        for(int j=0; j<n; j++){
            dfs(heights, 0, j, pacific);
            dfs(heights, m-1, j, atlantic);
        }

        // store the common visited cell
        vector<vector<int>> result;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};