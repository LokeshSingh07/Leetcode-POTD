// 2900. Longest Unequal Adjacent Groups Subsequence I

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> result;

        for(int i=0; i<n; i++){
            if(result.empty() || groups[i-1] != groups[i]){
                result.push_back(words[i]);
            }
        }

        return result;
    }
};