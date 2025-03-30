// 763. Partition Labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int endIdx = 0;
        unordered_map<char,int> mp;
        vector<int> result;

        for(int i=0; i<n; i++){
            mp[s[i]] = i;
        }

        while(i<n){
            endIdx = mp[s[i]];
            j=i;
            while(j<n && j <= endIdx){
                char ch = s[j];
                endIdx = max(endIdx, mp[ch]);
                j++;
            }

            result.push_back(j-i);      // cacth-> j ek index aage h
            i=j;
        }

        return result;
    }
};