// 2561. Rearranging Fruits

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;
        int mini = INT_MAX;

        for(auto &it: basket1){
            mp[it]++;
            mini = min(mini, it);
        }
        for(auto &it: basket2){
            mp[it]--;
            mini = min(mini, it);
        }

        vector<int> extra;
        for(auto &it: mp){
            int val = it.first;
            int count = it.second;
            if(count == 0) continue;
            if(count & 1) return -1;

            for(int c=0; c<abs(count)/2; c++){
                extra.push_back(val);
            }
        }

        sort(begin(extra), end(extra));
        
        long long result = 0;
        for(int i=0; i<extra.size()/2; i++){
            result += min(extra[i], mini*2);
        }

        return result;
    }
};