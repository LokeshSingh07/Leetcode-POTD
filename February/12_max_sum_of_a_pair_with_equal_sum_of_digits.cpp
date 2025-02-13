// 2342. Max Sum of a Pair With Equal Sum of Digits

class Solution {
public:
    int sumOfDigit(int num){
        int sum = 0;
        while(num > 0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;         // {digitSum, num}

        int maxi = -1;
        for(int i=0; i<n; i++){
            int digitSum = sumOfDigit(nums[i]);
            if(mp.count(digitSum)){
                maxi = max(maxi, mp[digitSum] + nums[i]);
            }

            // mp[digitSum] = nums[i];      // maximum store krna chahiye
            mp[digitSum] = max(mp[digitSum], nums[i]);
        }

        return maxi;
    }
};