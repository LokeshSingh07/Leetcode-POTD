// 3439. Reschedule Meetings for Maximum Free Time I

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeTime;

        freeTime.push_back(startTime[0]);
        for(int i=1; i<n; i++){
            freeTime.push_back(startTime[i] - endTime[i-1]);
        }
        freeTime.push_back(eventTime - endTime[n-1]);


        // sliding window
        int i=0, j=0;
        int currFreeTime=0;
        int maxFreeTime=0;
        n = freeTime.size();

        while(j<n){
            currFreeTime += freeTime[j];

            if(j-i+1 > k+1){
                currFreeTime -= freeTime[i];
                i++;
            }

            maxFreeTime = max(maxFreeTime, currFreeTime);
            j++;
        }

        return maxFreeTime;
    }
};