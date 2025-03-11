// 3306. Count of Substrings Containing Every Vowel and K Consonants II

class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        unordered_map<char,int> mp;
        vector<int> nextCons(n);
        int lastConsIdx = n;
        for(int i=n-1; i>=0; i--){
            nextCons[i] = lastConsIdx;
            if(!isVowel(word[i])){
                lastConsIdx = i;
            }
        }


        // sliding window
        int i=0;
        int j=0;
        long long count = 0;
        int cons = 0;
        while(j < n){
            char ch = word[j];
            if(isVowel(ch)) mp[ch]++;
            else cons++;

            // const mo=ust be of k size
            while(cons > k){
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch]==0) mp.erase(ch);
                }
                else cons--;
                i++;
            }

            // valid window
            while(mp.size() == 5 && cons == k){
                int idx = nextCons[j];
                count += idx-j;
                // window shrink
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch]==0) mp.erase(ch);
                }
                else cons--;

                i++;
            }

            j++;
        }

        return count;
    }
};