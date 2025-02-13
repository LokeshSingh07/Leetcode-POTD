// 1790. Check if One String Swap Can Make Strings Equal

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        vector<int> freq(26,0);
        int cnt=0;

        for(int i=0; i<n; i++){
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }

        for(int i=0; i<26; i++) if(freq[i] != 0) return false;

        for(int i=0; i<n; i++) if(s1[i] != s2[i]) cnt++;

        return cnt<=2;
    }
};