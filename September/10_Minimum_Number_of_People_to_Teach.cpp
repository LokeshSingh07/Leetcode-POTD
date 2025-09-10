// 1733. Minimum Number of People to Teach

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = friendships.size();
        unordered_set<int> sadUsers;

        for(int i=0; i<m; i++){
            int u = friendships[i][0] - 1;
            int v = friendships[i][1] - 1;

            unordered_set<int> se;
            for(auto l:languages[u]){
                se.insert(l);
            }

            bool canTalk = false;
            for(auto l:languages[v]){
                if(se.find(l) != se.end()){
                    canTalk = true;
                }
            }
            if(!canTalk){
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }

        vector<int> count(n+1, 0);
        int maxTakedlanguage = 0;
        for(auto user: sadUsers){
            for(int i=0; i<languages[user].size(); i++){
                count[languages[user][i]]++;
                maxTakedlanguage = max(maxTakedlanguage, count[languages[user][i]]);
            }
        }

        return sadUsers.size() - maxTakedlanguage;
    }
};