// 2901. Longest Unequal Adjacent Groups Subsequence II

class Solution {
public:
    bool hammingDist(string s1, string s2){
        int count = 0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]) count++;
            if(count > 1) return false;
        }
        return true;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n+1, 1);
        vector<int> parent(n+1, -1);
        vector<string> result;
        int prevIdx = 0;
        int maxLisLen = 0;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if((groups[i] != groups[j]) && (words[i].length() == words[j].length()) && hammingDist(words[i], words[j])==1){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        parent[i] = j;

                        if(maxLisLen < dp[i]){
                            maxLisLen = dp[i];
                            prevIdx = i;
                        }
                    }
                }
            }
        }

        while(prevIdx !=-1){
            result.push_back(words[prevIdx]);
            prevIdx = parent[prevIdx];
        }

        reverse(begin(result), end(result));
        return result;
        
    }
};