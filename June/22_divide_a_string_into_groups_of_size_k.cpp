// 2138. Divide a String Into Groups of Size k

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> result;
        int curr = 0;

        while(curr < n){
            result.push_back(s.substr(curr, k));
            curr += k;
        }

        if(result.back().length() != k){
            int remain = k-result.back().length();
            result.back() += string(remain, fill);
        }

        return result;
    }
};