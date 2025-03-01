// 2375. Construct Smallest Number From DI String

class Solution {
public:
    bool check(string result, string pattern){
        for(int i=0; i<pattern.size(); i++){
            if((pattern[i] == 'I' && result[i] > result[i+1]) || (pattern[i] == 'D' && result[i] < result[i+1])) return false;
        }
        return true;
    }

    string smallestNumber(string pattern) {
        int n = pattern.size();        
        string result = "";

        for(int i=1; i<=n+1; i++){
            result.push_back(i+'0');
        }

        while(!check(result, pattern)){
            next_permutation(result.begin(), result.end());
        }

        return result;
    }
};