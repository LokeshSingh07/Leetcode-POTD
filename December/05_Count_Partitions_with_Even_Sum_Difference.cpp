// 3432. Count Partitions with Even Sum Difference

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;

        for(auto num:nums) sum += num;

        return sum&1 ? 0 : nums.size()-1;
    }
};