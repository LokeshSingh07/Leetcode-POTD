// 3346. Maximum Frequency of an Element After Performing Operations I

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEle = *max_element(begin(nums), end(nums));
        vector<int> freq(maxEle+1, 0);
        int result = 1;

        for(auto &num: nums){
            freq[num]++;
        }

        for(int i=1; i<=maxEle; i++){
            freq[i] += freq[i-1];
        }

        for(int i=0; i<=maxEle; i++){
            if(freq[i] == 0) continue;

            int left = max(0, i-k);
            int right = min(maxEle, i+k);

            int totalCount = freq[right] - (left > 0 ? freq[left-1] : 0);
            int targetCount = freq[i] - (i > 0 ? freq[i-1] : 0);
            int need = totalCount - targetCount;
            int possible = targetCount + min(numOperations, need);

            result = max(result, possible);
        }

        return result;
    }
};