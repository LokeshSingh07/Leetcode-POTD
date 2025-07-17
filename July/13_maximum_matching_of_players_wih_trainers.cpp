// 2410. Maximum Matching of Players With Trainers

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();

        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));

        int i=0,j=0;
        int count = 0;
        while(i<n && j<m){
            if(players[i] <= trainers[j]){
                i++;
                j++;
                count++;
            }
            else{
                j++;
            }
        }

        return count;
    }
};