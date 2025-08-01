// 3480. Maximize Subarrays After Removing One Conflicting Pair

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int m = conflictingPairs.size();
        unordered_map<int, vector<int>> mp;
        vector<long long> extra(n+1);

        for(auto &pair: conflictingPairs){
            int u = min(pair[0], pair[1]);
            int v = max(pair[0], pair[1]);
            mp[v].push_back(u);
        }


        int maxRestrSP=0, secMaxRestrSP=0;
        long long result = 0;

        for(int end=1; end<=n; end++){

            // find max, secondMax
            for(auto &p: mp[end]){
                if(p >= maxRestrSP){
                    secMaxRestrSP = maxRestrSP;
                    maxRestrSP = p;
                }
                else if(p > secMaxRestrSP){
                    secMaxRestrSP = p;
                }
            }

            long long valid = end - maxRestrSP;
            result += valid;

            extra[maxRestrSP] += maxRestrSP - secMaxRestrSP;
        }

        return result + *max_element(begin(extra), end(extra));
    }
};