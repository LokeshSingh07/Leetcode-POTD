// 1317. Convert Integer to the Sum of Two No-Zero Integers

class Solution {
public:
    bool check(int n){
        string str = to_string(n);
        for(auto ch:str){
            if(ch == '0') return false;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int i=1; i<n; i++){
            if(check(i) && check(n-i)){
                return {i, n-i};
            }
        }

        return {};
    }
};