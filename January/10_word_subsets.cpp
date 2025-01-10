// 916. Word Subsets

class Solution {
public:
    bool isUniversal(vector<int> freq1, vector<int> freq2){
        for(int i=0; i<26; i++){
            if(freq1[i] < freq2[i]) return false;
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> mp2(26, 0);

        // step1: store the max freq in map
        for(auto word: words2){
            vector<int> temp(26, 0);
            for(int j=0; j<word.size(); j++){
                char ch = word[j];
                temp[ch-'a']++;
                mp2[ch-'a'] = max(temp[ch-'a'], mp2[ch-'a']);
            }
        }


        // step2: check for every string in words1
        vector<string> ans;
        for(auto word: words1){
            vector<int> freq(26,0);
            for(int j=0; j<word.size(); j++){
                char ch = word[j];
                freq[ch-'a']++;
            }
            if(isUniversal(freq, mp2)) ans.push_back(word);
        }
    
        return ans;
    }
};