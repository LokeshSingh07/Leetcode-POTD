// 3442. Maximum Difference Between Even and Odd Frequency I

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }

        int oddFreq=INT_MIN, evenFreq=INT_MAX;
        for(auto it: mp){
            int freq = it.second;
            if((freq & 1) != 1){
                evenFreq = min(evenFreq, freq);
            }else{
                oddFreq = max(oddFreq, freq);
            }
        }

        return oddFreq - evenFreq;
    }
};