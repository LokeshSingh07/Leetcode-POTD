// 3342. Find Minimum Time to Reach Last Room II

class Solution {
public:
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    typedef pair<int,pair<int,int>> P;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0,{0,0}});
        result[0][0] = 0;

        while(!pq.empty()){
            int currTime = pq.top().first;
            auto cell = pq.top().second;
            pq.pop();
            int i = cell.first;
            int j = cell.second;

            if(i==m-1 && j==n-1){
                return currTime;
            }

            for(auto &dir: directions){
                int newX = i + dir[0];
                int newY = j + dir[1];

                if(newX>=0 && newX<m && newY>=0 && newY<n){
                    int moveCount = (newX+newY)&1 ? 1 : 2;
                    int wait = max(moveTime[newX][newY] - currTime, 0);
                    int arrTime = currTime + wait + moveCount;

                    if(result[newX][newY] > arrTime){
                        pq.push({arrTime, {newX, newY}});
                        result[newX][newY] = arrTime;
                    }
                }
            }
        }

        return -1;
    }
};