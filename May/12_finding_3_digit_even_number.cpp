// 2094. Finding 3-Digit Even Numbers

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> st;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(i!=j && i!=k && j!=k){
                        int num = digits[i]*100 + digits[j]*10 + digits[k];
                        if(num%2 == 0 && num>=100){
                            st.insert(num);
                        }
                    }
                }
            }
        }

        vector<int> ans;
        for(auto n:st){
            ans.push_back(n);
        }

        sort(begin(ans), end(ans));
        return ans;
    }
};