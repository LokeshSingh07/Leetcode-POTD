// 3541. Find Most Frequent Vowel and Consonant

class Solution {
public:
    bool isVowel(char ch){
        return string("aeiou").find(ch) != string::npos;
    }

    int maxFreqSum(string s) {
        unordered_map<char,int> vowels;
        unordered_map<char,int> consonants;

        for(auto ch:s){
            if(isVowel(ch)) vowels[ch]++;
            else consonants[ch]++;
        }

        int maxVow=0;
        for(auto it:vowels){
            maxVow = max(maxVow, it.second);
        }

        int maxCons=0;
        for(auto it:consonants){
            maxCons = max(maxCons, it.second);
        }

        return maxVow + maxCons;
    }
};