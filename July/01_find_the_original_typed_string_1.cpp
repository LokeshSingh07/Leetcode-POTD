// 3330. Find the Original Typed String I

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int result = 1;

        for(int i=1; i<n; i++){
            if(word[i] == word[i-1]) result++;
        }

        return result;
    }
};