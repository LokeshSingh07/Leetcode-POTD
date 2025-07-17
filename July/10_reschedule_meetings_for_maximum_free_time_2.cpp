// 3440. Reschedule Meetings for Maximum Free Time II

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeArray;
        freeArray.push_back(startTime[0]);

        for(int i=1; i<n; i++){
            freeArray.push_back(startTime[i] - endTime[i-1]);
        }

        freeArray.push_back(eventTime - endTime[n-1]);

        n = freeArray.size();
        vector<int> maxLeftFree(n, 0);
        vector<int> maxRightFree(n, 0);

        for(int i=n-2; i>=0; i--){
            maxRightFree[i] = max(maxRightFree[i+1], freeArray[i+1]);
        }

        for(int i=1; i<n; i++){
            maxLeftFree[i] = max(maxLeftFree[i-1], freeArray[i-1]);
        }

        int result = 0;
        for(int i=1; i<n; i++){
            int curr = endTime[i-1] - startTime[i-1];

            if(curr <= max(maxLeftFree[i-1], maxRightFree[i])){
                result  = max(result, freeArray[i-1] + curr + freeArray[i]);
            }

            result =  max(result, freeArray[i-1] + freeArray[i]);
        }

        return result;
    }
};