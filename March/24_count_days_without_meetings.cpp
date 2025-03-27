// 3169. Count Days Without Meetings

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(begin(meetings), end(meetings));

        int totalMeetingOccurInDays = 0;
        int start = meetings[0][0];
        int end = meetings[0][1];

        for(int i=1; i<n; i++){
            if(end >= meetings[i][0]){
                end = max(end, meetings[i][1]);
            }
            else{
                totalMeetingOccurInDays += end-start+1;
                start = meetings[i][0];
                end = meetings[i][1];
            }
        }
        totalMeetingOccurInDays += end-start+1;

        return days-totalMeetingOccurInDays;
    }
};