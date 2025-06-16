// 386. Lexicographical Numbers

class Solution {
public:
    void solve(int num, int &n, vector<int> &result){
        if(num > n) return;
        result.push_back(num);

        for(int i=0; i<=9; i++){
            int newNum = (num*10) + i;
            if(newNum > n) return;
            solve(newNum, n, result);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;

        for(int i=1; i<=9; i++){
            solve(i, n, result);
        }

        return result;        
    }
};