// 1399. Count Largest Group

class Solution {
public:
    int findDigitSum(int num){
        int sum=0;
        while(num > 0){
            int digit = num%10;
            sum += digit;
            num /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        int count=0, groupSize=0;

        for(int i=1; i<=n; i++){
            int digitSum = findDigitSum(i);
            mp[digitSum]++;

            if(mp[digitSum] == groupSize) count++;
            else if(mp[digitSum] > groupSize){
                groupSize = mp[digitSum];
                count=1;
            }
        }

        return count;
    }
};