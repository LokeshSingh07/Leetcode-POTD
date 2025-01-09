// 1769. Minimum Number of Operations to Move All Balls to Each Box

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);

        unordered_set<int> st;
        for(int i=0; i<n; i++){
            if(boxes[i] == '1') st.insert(i);
        }

        for(int i=0; i<n; i++){
            for(auto it: st){
                ans[i] += abs(it-i);
            }
        }

        return ans;
    }
};