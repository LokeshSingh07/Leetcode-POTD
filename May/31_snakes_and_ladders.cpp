// 909. Snakes and Ladders

class Solution {
public:
    int n;
    pair<int,int> getCoordinate(int num){
        int RT = (num-1) / n;
        int RB = (n-1) - RT;

        int col = (num-1)%n;
        if((n%2==1 && RB%2==1) || (n%2==0 && RB%2==0)){
            col = (n-1) - col;
        }

        return {RB, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        queue<int> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int steps = 0;
        visited[n-1][0] = true;
        q.push(1);

        while(!q.empty()){
            int N = q.size();

            while(N--){
                int x = q.front();
                q.pop();

                if(x == n*n) return steps;

                for(int k=1; k<=6; k++){
                    int val = x + k;
                    if(val > n*n) break;
                    auto [r,c] = getCoordinate(val);

                    if(visited[r][c]) continue;
                    visited[r][c] = true;

                    if(board[r][c] == -1){
                        q.push(val);
                    }else{
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};