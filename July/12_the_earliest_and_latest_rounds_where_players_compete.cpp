// 1900. The Earliest and Latest Rounds Where Players Compete

class Solution {
public:
    int minRound=INT_MAX, maxRound=INT_MIN;
    int p1, p2;

    void solve(vector<int> &players, int round){
        int n = players.size();

        // check
        for(int i=0; i<n/2; i++){
            if(players[i] == p1 && players[n-i-1] == p2){
                minRound = min(minRound, round);
                maxRound = max(maxRound, round);
                return;
            }
        }

        bool f1=false, f2=false;
        int half = n/2;
        for(auto n: players){
            f1 |= (n == p1);
            f2 |= (n == p2);
        }

        if(!f1 || !f2) return;

        vector<int> nextArr(half + (n % 2));
        int m = (1 << half) - 1;
        for(int i = 0; i <= m; i++) { 
            int left = 0, right = nextArr.size() - 1;
            for(int j = 0; j < half; j++) {
                if((1 << j) & i) { 
                    nextArr[left++] = players[j];
                }else { 
                    nextArr[right--] = players[n - j - 1];
                }
                
            }
            if(n % 2) { 
                nextArr[left] = players[n / 2];
            }
            solve(nextArr, round + 1);
        }

    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> players(n);
        iota(begin(players), end(players), 1);

        int round = 1;
        p1=firstPlayer, p2=secondPlayer;

        solve(players, round);

        return {minRound, maxRound};
    }
};