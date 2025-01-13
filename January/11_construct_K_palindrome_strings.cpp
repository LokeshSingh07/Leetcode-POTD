// 1400. Construct K Palindrome Strings

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n < k) return false;
        int oddCnt = 0;

        vector<int> freq(26, 0);
        for(int i=0; i<n; i++){
            char ch = s[i];
            freq[ch-'a']++;
        }


        // count the odd no. of freq char
        for(int i=0; i<26; i++){
            if(freq[i] & 1) oddCnt++;
        }

        if(oddCnt <= k) return true;
        return false;
    }
};