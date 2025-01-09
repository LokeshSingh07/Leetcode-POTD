// 2381. Shifting Letters II

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();

        // step1: create diff array
        vector<int> diff(n);
        for(auto shift: shifts){
            int start = shift[0];
            int end = shift[1];
            int dir = shift[2];
            int x;
            if(dir == 0) x = -1;
            else x = 1;

            diff[start] += x;
            if(end+1 < n) diff[end+1] -= x;
        }

        // step2: cumulative sum
        for(int i=1; i<n; i++){
            diff[i] += diff[i-1];
        }

        // step3: 
        for(int i=0; i<n; i++){
            diff[i] %= 26;
            if(diff[i] < 0) diff[i] += 26;

            s[i] = (((s[i]-'a') + diff[i]) % 26) + 'a';
        }

        return s;
    }
};