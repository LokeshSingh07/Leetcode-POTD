// 2273. Find Resultant Array After Removing Anagrams

class Solution {
public:
    bool checkAnagram(string &str1, string &str2){
        vector<int> freq(26,0);

        for(int i=0; i<str1.size(); i++) 
            freq[str1[i] - 'a']++;
        
        for(int i=0; i<str2.size(); i++)
            freq[str2[i] - 'a']--;
        
        for(int i=0; i<26; i++){
            if(freq[i] != 0) return false;
        }

        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> result;
        result.push_back(words[0]);

        for(int i=1; i<n; i++){
            if(!checkAnagram(words[i-1], words[i])) result.push_back(words[i]);
        }
        
        return result;
    }
};