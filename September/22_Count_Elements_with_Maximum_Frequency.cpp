// 3005. Count Elements With Maximum Frequency

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int result=0, maxFreq=1;

        for(auto num: nums){
            mp[num]++;
            maxFreq = max(maxFreq, mp[num]);
        };

        for(auto num: nums){
            if(mp[num] == maxFreq) result++;
        }

        return result;
    }
};