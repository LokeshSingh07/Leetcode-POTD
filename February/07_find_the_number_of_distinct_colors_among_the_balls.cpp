// 3160. Find the Number of Distinct Colors Among the Balls

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);

        unordered_map<int,int> mp;
        unordered_map<int,int> ballmp;

        for(int i=0; i<n; i++){
            int ball = queries[i][0];
            int color = queries[i][1];

            if(ballmp.count(ball)){
                int prevColor = ballmp[ball];
                mp[prevColor]--;

                // check if it's count becomes 0
                if(mp[prevColor] == 0){
                    mp.erase(prevColor);
                }
            }

            ballmp[ball] = color;
            mp[color]++;

            result[i] = mp.size();
        }

        return result;
    }
};