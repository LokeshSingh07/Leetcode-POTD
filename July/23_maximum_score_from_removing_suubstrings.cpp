// 1717. Maximum Score From Removing Substrings

class Solution {
public:
    void removeStr(string &s, string rs, int val, int &ans){
        stack<char> st;
        int n = s.size();
        char firstChar = rs[0];
        char secondChar = rs[1];

        for(int i=0; i<n; i++){
            char ch = s[i];
            if(!st.empty() && st.top() == firstChar && ch == secondChar){
                st.pop();
                ans += val;  
            }
            else st.push(ch);
        }

        string temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }

        reverse(begin(temp), end(temp));
        s = temp;
    }

    int maximumGain(string s, int x, int y) {
        int ans = 0;
        
        if(x > y){
            removeStr(s, "ab", x, ans);
            removeStr(s, "ba", y, ans);
        }
        else{
            removeStr(s, "ba", y, ans);
            removeStr(s, "ab", x, ans);
        }
        return ans;
    }
};