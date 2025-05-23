// 873. Length of Longest Fibonacci Subsequence

class Solution {
public:
    int solve(int j, int k, vector<int> &arr, unordered_map<int, int> &mp){
        int target = arr[k] - arr[j];
        if(mp.count(target) && mp[target] < j){
            int i = mp[target];
            return solve(i, j, arr, mp) + 1;
        }
        return 2;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++){
            mp[arr[i]] = i;
        }

        int  maxLength = 0;
        for(int j=1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                int length = solve(j, k, arr, mp);
                if(length >= 3){
                    maxLength = max(maxLength, length);
                }
            }
        }

        return maxLength;
    }
};