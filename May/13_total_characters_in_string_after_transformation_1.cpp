// 3335. Total Characters in String After Transformations I

// Method1: TLE (hasmap)
class Solution {
public:
    int MOD = 1e9+7;

    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        unordered_map<char,int> mp;

        for(auto &ch: s){
            mp[ch]++;
        }

        for(int i=1; i<=t; i++){
            unordered_map<char,int> temp;
            for(auto &it: mp){
                char ch = it.first;
                int freq = it.second;
            
                if(ch != 'z'){
                    temp[ch+1] =  (temp[ch+1] + freq) % MOD;
                }else{
                    temp['a'] = (temp['a'] + freq) % MOD;
                    temp['b'] = (temp['b'] + freq) % MOD; 
                }
            }
            mp = move(temp);
        }


        int result = 0;
        for(auto &it: mp){
            result = (result + it.second) % MOD;
        }

        return result;
    }
};


// Method2: 26 size Vector
class Solution {
public:
    int MOD = 1e9+7;

    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        unordered_map<char,int> mp;

        for(auto &ch: s){
            mp[ch]++;
        }

        for(int i=1; i<=t; i++){
            unordered_map<char,int> temp;
            for(auto &it: mp){
                char ch = it.first;
                int freq = it.second;
            
                if(ch != 'z'){
                    temp[ch+1] =  (temp[ch+1] + freq) % MOD;
                }else{
                    temp['a'] = (temp['a'] + freq) % MOD;
                    temp['b'] = (temp['b'] + freq) % MOD; 
                }
            }
            mp = move(temp);
        }


        int result = 0;
        for(auto &it: mp){
            result = (result + it.second) % MOD;
        }

        return result;
    }
};