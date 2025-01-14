// 2657. Find the Prefix Common Array of Two Arrays

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int count = 0;
        vector<int> ans(n);
        unordered_set<int> st;

        for(int i=0; i<n; i++){
            if(st.count(A[i])) count++;
            else st.insert(A[i]);

            if(st.count(B[i])) count++;
            else st.insert(B[i]);
        
            ans[i] = count;
        }

        return ans;
    }
};