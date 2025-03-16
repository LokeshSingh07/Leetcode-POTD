// 2226. Maximum Candies Allocated to K Children

class Solution {
public:
    bool isValid(vector<int> &candies, long long k, int mid){
        long long count=0;
        for(int i=0; i<candies.size(); i++){
            count += candies[i]/mid;
            if(count >= k) return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long totalSum = 0;
        int maxCandie = 0;

        for(int i=0; i<n; i++){
            totalSum + candies[i];
            maxCandie = max(maxCandie, candies[i]);
        }

        int s=1, e=maxCandie;
        int count = 0;
        while(s<=e){
            int mid = s+(e-s)/2;

            if(isValid(candies, k, mid)){
                count = mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }

        return count;
    }
};