// 2503. Maximum Number of Points From Grid Queries

// Method 1: TLE
class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    bool isSafe(vector<vector<int>> & grid, vector<vector<bool>> &visited, int i, int j, int Q){
        return (i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && !visited[i][j] && grid[i][j]  <Q);
    }

    int BFS(vector<vector<int>> &grid, int Q){
        int m = grid.size();  
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int points = 0; 
        q.push({0,0});
        visited[0][0] = true;

        while(!q.empty()){
            int N = q.size();
            while(N--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if(grid[x][y] > Q) continue;

                points++;

                for(auto &dir: directions){
                    int newX = x + dir[0];
                    int newY = y + dir[1];

                    if(isSafe(grid, visited, newX, newY, Q)){
                        q.push({newX, newY});
                        visited[newX][newY] = true;
                    }
                }
            }
        }

        return points;
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int> result;

        for(auto &q: queries){
            result.push_back(BFS(grid, q));
        }

        return result;
    }
};


// Method 2: 
class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int Q = queries.size();
        vector<pair<int,int>> sortedQ;

        for(int i=0; i<Q; i++){
            sortedQ.push_back({queries[i], i});
        }

        sort(begin(sortedQ), end(sortedQ));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> result(Q);
        int points = 0;
        // initial state
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        for(auto &q: sortedQ){
            int val = q.first;
            int idx = q.second;

            while(!pq.empty() && pq.top()[0] < val){
                int x = pq.top()[1];
                int y = pq.top()[2];
                pq.pop();
                points++;

                for(auto &dir: dirs){
                    int newX = x + dir[0];
                    int newY = y + dir[1];
                    if(newX>=0 && newX<m && newY>=0 && newY<n && !visited[newX][newY]){
                        pq.push({grid[newX][newY], newX, newY});
                        visited[newX][newY] = true;
                    }
                }
            }

            result[idx] = points;
        }

        return result;
    }
};