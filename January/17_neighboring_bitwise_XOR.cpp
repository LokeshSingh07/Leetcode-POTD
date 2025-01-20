// 2683. Neighboring Bitwise XOR

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> original(n);

        // by setting original[0] is 0;
        original[0] = 0;
        for(int i=0; i<n-1; i++){
            original[i+1] = original[i] ^ derived[i];
        }

        if((original[n-1] ^ derived[n-1]) == original[0]) return true;


        // by setting original[0] is 1;
        original[0] = 1;
        for(int i=0; i<n-1; i++){
            original[i+1] = original[i] ^ derived[i];
        }

        if((original[n-1] ^ derived[n-1]) == original[0]) return true;

        return false;
    }
};