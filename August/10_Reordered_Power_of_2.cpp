// 869. Reordered Power of 2

class Solution {
public:
    string signature(int n){
        string str = to_string(n);
        sort(begin(str), end(str));
        return str;
    }

    bool reorderedPowerOf2(int n) {
        unordered_set<string> st;

        for(int i=0; i<32; i++){
            int pow = (1<<i);
            string str = signature(pow);
            st.insert(str);
        }

        string str = signature(n);

        return st.count(str);
    }
};