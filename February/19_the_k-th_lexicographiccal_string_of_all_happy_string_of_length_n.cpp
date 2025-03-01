// 1415. The k-th Lexicographical String of All Happy Strings of Length n

class Solution {
public:
    void solve(int n, string curr, vector<string> &result){
        if(curr.size() == n){
            result.push_back(curr);
            return;
        }

        for(char ch='a'; ch<='c'; ch++){
            if(!curr.empty() && curr.back() == ch) continue;

            curr.push_back(ch);
            solve(n, curr, result);
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> result;

        solve(n, curr, result);
        if(k > result.size()) return "";

        return result[k-1];
    }
};