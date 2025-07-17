// 2311. Longest Binary Subsequence Less Than or Equal to K

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int powVal = 1;
        int len = 0;

        for(int i=n-1; i>=0; i--){
            if(s[i]=='0') len++;
            else if(powVal <= k){
                k -= powVal;
                len++;
            }

            if(powVal <= k){
                powVal <<= 1;
            }
        }

        return len;
    }
};