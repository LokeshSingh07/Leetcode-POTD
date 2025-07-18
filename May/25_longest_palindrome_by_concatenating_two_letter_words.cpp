// 2131. Longest Palindrome by Concatenating Two Letter Words

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int result = 0;

        for(auto word: words){
            string revWord = word;
            swap(revWord[0], revWord[1]);

            if(mp[revWord] > 0){
                result += 4;
                mp[revWord]--;
            }
            else{
                mp[word]++;
            }
        }

        for(auto it: mp){
            string word = it.first;
            int count = it.second;
            if(word[0] == word[1] && count>0){
                result+=2;
                break;
            }
        }

        return result;
    }
};