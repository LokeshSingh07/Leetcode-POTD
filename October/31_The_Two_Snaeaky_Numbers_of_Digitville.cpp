// 3289. The Two Sneaky Numbers of Digitville

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> result;

        for(int num: nums){
            mp[num]++;
        }

        for(auto it: mp){
            if(it.second == 2){
                result.push_back(it.first);
            }
        }

        return result;
    }
};