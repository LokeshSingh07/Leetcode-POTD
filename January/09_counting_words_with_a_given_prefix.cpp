// 2185. Counting Words With a Given Prefix

// Given a list of words, return the number of words that can be formed using the given prefix.
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int n = pref.size();

        for(auto word: words){
            if(word.substr(0, n) == pref) count++;
        }
        return count;
    }
};



// same as above but using a function to check prefix
class Solution {
public:
    bool checkPrefix(string word, string pref){
        int n = pref.size();
        int m = word.size();
        int i;
        
        for(i=0; i<n && i<m; i++)
            if(word[i] != pref[i]) return 0;
    
        return (i==n) ? 1 : 0;
    }

    int prefixCount(vector<string>& words, string pref) {
        int count = 0;

        for(auto word: words){
            if(checkPrefix(word, pref)) count++;
        }
        return count;
    }
};