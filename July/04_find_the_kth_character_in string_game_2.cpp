// 3307. Find the K-th Character in String Game II

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1) return 'a';

        long long len = 1;
        long long newK;
        bool opn;
        
        for(int i=0; i<operations.size(); i++){
            len *= 2;
            if(len >= k){
                newK = k - len/2;
                opn = operations[i];
                break;
            }
        }

        char ch = kthCharacter(newK, operations);

        if(opn == 0) return ch;
        
        return ch=='z' ? 'a' : ch+1;
    }
};