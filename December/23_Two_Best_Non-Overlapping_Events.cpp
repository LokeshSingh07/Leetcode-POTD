// 2054. Two Best Non-Overlapping Events

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(begin(events), end(events));
        vector<int> suffixMax(n, 0);
        suffixMax[n-1] = events[n-1][2];
        for(int i=n-2; i>=0; i--){
            suffixMax[i] = max(suffixMax[i+1], events[i][2]);
        }

        int result = 0;
        for(int i=0; i<n; i++){
            int end = events[i][1];
            int value = events[i][2];

            auto it = lower_bound( events.begin(), events.end(), vector<int>{end + 1, 0, 0} );

            if(it != events.end()){
                int idx = it - events.begin();
                result = max(result, value + suffixMax[idx]);
            }
            else{
                result = max(result, value);
            }
        }

        return result;
    }
};