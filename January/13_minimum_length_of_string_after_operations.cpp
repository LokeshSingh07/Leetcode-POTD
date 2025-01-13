// 3223. Minimum Length of String After Operations

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        vector<int> ans(26,0);

        for(int i=0; i<n; i++){
            char ch = s[i];
            ans[ch-'a']++;
        }


        int len = 0;
        for(int i=0; i<26; i++){
            if(ans[i] != 0){
                if(ans[i]&1) len += 1;
                else len += 2;
            }
        }

        return len;
    }
};