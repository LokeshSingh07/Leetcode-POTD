// 1524. Number of Sub-arrays With Odd Sum

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        int even=1, odd=0;
        int mod = 1e9+7;
        int prefixSum=0;

        for(int ele: arr){
            prefixSum += ele;
            if(prefixSum & 1){      // odd 
                count = (count + even) % mod;
                odd++;
            }
            else{
                count = (count + odd) % mod;
                even++;
            }
        }

        return count;
    }
};