// 2425. Bitwise XOR of All Pairings

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        int XOR1=0, XOR2=0;

        // even-even
        if(!(l1&1) && !(l2&1)) return XOR1;

        for(int i=0; i<l1; i++){
            XOR1 ^= nums1[i];
        }
        
        for(int i=0; i<l2; i++){
            XOR2 ^= nums2[i];
        }
        
        if((l1&1) && (l2&1)){       // odd-odd
            return XOR1^XOR2;
        }

        return l1&1 ? XOR2 : XOR1;
    }
};