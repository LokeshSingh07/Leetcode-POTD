// 1910. Remove All Occurrences of a Substring

// Method1 : Using stack
class Solution {
public:
    bool check(stack<char> &st, string &part, int &n){
        stack<char> temp = st;

        for(int i=n-1; i>=0; i--){
            if(temp.top() != part[i]) return false;
            temp.pop();
        }

        return true;
    }

    string removeOccurrences(string s, string part) {
        int m = s.size();
        int n = part.length();
        stack<char> st;

        for(int i=0; i<m; i++){
            st.push(s[i]);
            if(st.size() >=n && check(st, part, n)){
                for(int j=0; j<n; j++){
                    st.pop();
                }
            }
        }

        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};



// Method 2
class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while(s.find(part) != string::npos){
            s.erase(s.find(part), part.length());
        }

        return s;
    }
};