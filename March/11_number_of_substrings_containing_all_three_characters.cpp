// 1358. Number of Substrings Containing All Three Characters

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<int,int> mp;

        int i=0,j=0;
        int result=0;
        while(j < n){
            char ch = s[j];
            mp[ch]++;

            while(mp.size()==3){
                result += n-j;
                ch = s[i];
                mp[ch]--;
                if(mp[ch]==0) mp.erase(ch);
                i++; 
            }

            j++;
        }

        return result;
    }
};