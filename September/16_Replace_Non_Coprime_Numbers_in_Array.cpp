// 2197. Replace Non-Coprime Numbers in Array

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;

        for(auto num: nums){
            while(!result.empty()){
                int curr = num;
                int prev = result.back();

                int GCD = gcd(curr, prev);
                if(GCD == 1) break;

                result.pop_back();
                int LCM = prev/GCD * curr;
                num = LCM;
            }
            result.push_back(num);
        }

        return result;
    }
};