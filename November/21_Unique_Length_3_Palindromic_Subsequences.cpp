// 1930. Unique Length-3 Palindromic Subsequences

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_set<char> letters;

        // insert unique letter in set
        for(int i=0; i<n; i++){
            letters.insert(s[i]);
        }

        int count = 0;
        for(char letter: letters){
            int leftIdx = -1;
            int rightIdx = -1;

            for(int i=0; i<n; i++){
                if(s[i] == letter){
                    if(leftIdx == -1) leftIdx = i;
                    rightIdx = i;
                } 
            }

            // count the unique no. of letter between them
            unordered_set<char> st;
            for(int i=leftIdx+1; i<rightIdx; i++){
                st.insert(s[i]);
            }

            count += st.size();
        }

        return count;
    }
};