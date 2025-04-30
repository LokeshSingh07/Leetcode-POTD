// 1295. Find Numbers with Even Number of Digits

class Solution {
public:
    bool check(int num){
        int count = 0;
        while(num != 0){
            num /= 10;;
            count++;
        }

        return count&1 ? false: true;
    }

    int findNumbers(vector<int>& nums) {
        int evenCount = 0;

        for(auto num: nums){
            if(check(num)) evenCount++;
        }

        return evenCount;
    }
};