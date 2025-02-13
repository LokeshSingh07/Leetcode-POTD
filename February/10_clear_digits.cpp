// 3174. Clear Digits

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        int n = s.size();
        string str;

        for(int i=0; i<n; i++){
            char ch = s[i];
            if(!st.empty() && (ch>='0' && ch<='9')) st.pop();
            else st.push(ch);
        }

        while(!st.empty()){
            str.push_back(st.top());
            st.pop();
        }

        reverse(begin(str), end(str));

        return str;
    }
};