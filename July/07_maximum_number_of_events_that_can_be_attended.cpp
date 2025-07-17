// 1353. Maximum Number of Events That Can Be Attended

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(begin(events), end(events));
        priority_queue<int, vector<int>, greater<int>> pq;

        int day=events[0][0];;
        int eventsCount = 0;
        int i=0;
        int n = events.size();

        while(!pq.empty() || i<n){
            while(i<n && events[i][0] == day){
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()){
                pq.pop();
                eventsCount++;
            }

            day++;

            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }
        }

        return eventsCount;
    }
};