// 898. Bitwise ORs of Subarrays

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> curr, prev;

        for(int i=0; i<arr.size(); i++){
            for(auto it: prev){
                curr.insert(it | arr[i]);
                result.insert(arr[i] | it);
            }

            curr.insert(arr[i]);
            result.insert(arr[i]);

            prev = curr;
            curr.clear();
        }

        return result.size();
    }
};