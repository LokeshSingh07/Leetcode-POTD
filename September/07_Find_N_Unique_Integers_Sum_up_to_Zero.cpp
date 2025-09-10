// 1304. Find N Unique Integers Sum up to Zero

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;

        for(int i=1; i<=n/2; i++){
            result.push_back(i);
            result.push_back(-i);
        }

        if(n&1) result.push_back(0);
        return result;
    }
};