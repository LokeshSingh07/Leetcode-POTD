// 2559. Count Vowel Strings in Ranges

class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' ||ch=='o' || ch=='u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> cumVow(n,0);

        for(int i=0; i<n; i++){
            string word = words[i];
            if(i > 0){
                if(isVowel(word.front()) && isVowel(word.back())){  // catch
                    cumVow[i] = cumVow[i-1] + 1;
                }
                else cumVow[i] = cumVow[i-1];
            }
            else{
                if(isVowel(word.front()) && isVowel(word.back())){
                    cumVow[i] = 1;
                }
            }
        }

        vector<int> ans;
        for(auto q:queries){
            int u = q[0];
            int v = q[1];

            if(u > 0) ans.push_back(abs(cumVow[v]-cumVow[u-1]));
            else ans.push_back(cumVow[v]);
        }

        return ans;
    }
};