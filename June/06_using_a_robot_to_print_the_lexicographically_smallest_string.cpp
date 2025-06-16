// 2434. Using a Robot to Print the Lexicographically Smallest String

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> minCharToRight(n);

        minCharToRight[n-1] = s[n-1];
        for(int i=n-2; i>=0; i--){
            minCharToRight[i] = min(minCharToRight[i+1], s[i]);
        }

        string t = "";
        string paper = "";
        for(int i=0; i<n; i++){
            t.push_back(s[i]);
            char minChar = (i+1 < n) ? minCharToRight[i+1] : s[i];
            while(!t.empty() && t.back() <= minChar){
                paper += t.back();
                t.pop_back();
            }
        }

        while(!t.empty()){
            paper += t.back();
            t.pop_back();
        }

        return paper;
    }
};