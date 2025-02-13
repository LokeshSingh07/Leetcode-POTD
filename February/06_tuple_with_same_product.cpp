// 1726. Tuple with Same Product

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int tuples=0;

        for(int i=0; i<n; i++){
            for(int j=n-1; j>i; j--){
                int product = nums[i]*nums[j];
                unordered_set<int> st;
                for(int k=i+1; k<j; k++){
                    if(product % nums[k] == 0){
                        int val = product / nums[k];
                        if(st.count(val)) tuples++;
                        st.insert(nums[k]);
                    }
                }
            }
        }

        return tuples*8;
    }
};