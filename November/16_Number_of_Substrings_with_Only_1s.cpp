// 1513. Number of Substrings With Only 1s

// Approach-1:
class Solution {
public:
    int M = 1e9+7;

    int numSub(string s) {
        int n = s.size();
        int result = 0;
        int i = 0, j= 0;

        while(j < n){
            if(s[j] == '1'){
                int count = abs(j-i+1);
                result = (result + count) % M; 
            }
            else i = j+1;

            j++;
        }

        return result;
    }
};



// Approach-2:
class Solution {
public:
    int M = 1e9+7;

    int numSub(string s) {
        int n = s.size();
        int result = 0;
        int count = 0;
        int j = 0;

        while(j < n){
            if(s[j] == '1'){
                count++;
                result = (result + count) % M; 
            }
            else count = 0;

            j++;
        }

        return result;
    }
};