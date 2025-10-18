// 1488. Avoid Flood in The City


class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int,int> mp;      // lake->day
        set<int> se;
        vector<int> result(n, 1);

        for(int i=0; i<n; i++){
            int lake = rains[i];
            
            if(lake == 0){
                se.insert(i);
            }else{
                result[i] = -1;

                if(mp.find(lake) != mp.end()){
                    auto it = se.lower_bound(mp[lake]);
                    if(it == se.end()) return {};
                    result[*it] = lake;
                    se.erase(it);
                }

                mp[lake] = i;
            }
        }

        return result;
    }
};