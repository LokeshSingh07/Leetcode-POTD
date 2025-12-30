// 2402. Meeting Rooms III

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));
        
        vector<int> roomUsedCount(n, 0);
        vector<long long> roomAvailableAt(n, 0);

        for(auto meeting: meetings){
            int start = meeting[0];
            int end = meeting[1];
            int duration = end - start;

            int earlyFreeRoom = 0;
            long long earlyFreeTime = LLONG_MAX;
            bool found = false;

            for(int room = 0; room<n; room++){
                if(roomAvailableAt[room] <= start){
                    roomAvailableAt[room] = end;
                    roomUsedCount[room]++;
                    found = true;
                    break;
                }

                if(roomAvailableAt[room] < earlyFreeTime){
                    earlyFreeRoom = room;
                    earlyFreeTime = roomAvailableAt[room];
                }
            }

            if(!found){
                roomAvailableAt[earlyFreeRoom] += duration;
                roomUsedCount[earlyFreeRoom]++;
            }
        }


        int room = 0;
        int maxUsedRoom = 0;
        for(int i=0; i<n; i++){
            if(roomUsedCount[i] > maxUsedRoom){
                room = i;
                maxUsedRoom = roomUsedCount[i];
            }
        }


        return room;
    }
};