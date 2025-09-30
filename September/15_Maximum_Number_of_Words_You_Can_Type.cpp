// 1935. Maximum Number of Words You Can Type

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> mp(26, false);
        
        for(auto ch: brokenLetters){
            mp[ch-'a'] = true;
        }

        int count = 0;
        bool canTake = true;
        for(auto ch: text){
            if(ch == ' '){
                if(canTake) count++;
                canTake = true;
            }else{
                if(mp[ch-'a']) canTake = false;
            }
        }

        if(canTake) count++;

        return count;
    }
};