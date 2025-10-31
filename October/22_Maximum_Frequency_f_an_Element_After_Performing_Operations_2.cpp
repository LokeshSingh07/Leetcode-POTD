// 3347. Maximum Frequency of an Element After Performing Operations II

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEle = *max_element(begin(nums), end(nums))+k;
        int n = nums.size();
        unordered_map<int,int> freq;
        map<int,int> diff;

        for(auto num: nums){
            freq[num]++;

            int l = max(0, num - k);
            int r = min(num + k, maxEle);
            diff[l]++;
            diff[r+1]--;
            diff[num] += 0;     // catch
        }

        int result = 1;
        int cumSum = 0;
        for(auto it=diff.begin(); it!=diff.end(); it++){
            int target = it->first;
            it->second += cumSum;

            int targetCount = freq[target];
            int totalCount = it->second;
            int need = totalCount - targetCount;
            int possible = targetCount + min(need, numOperations);

            result = max(result, possible);
            cumSum = it->second;
        }

        return result;
    }
};