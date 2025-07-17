// 2402. Meeting Rooms III

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));

        vector<long long> lastAvailableAt(n, 0);
        vector<int> roomUsedCount(n, 0);


        for(auto &meeting: meetings){
            int start = meeting[0];
            int end   = meeting[1];
            int duration = end - start;
            bool found = false;

            long long earlyFreeRoomTime = LLONG_MAX;
            int earlyFreeRoom = 0;

            for(int room=0; room<n; room++){
                if(lastAvailableAt[room] <= start){
                    lastAvailableAt[room] = end;
                    roomUsedCount[room]++;
                    found = true;
                    break;
                }

                if(lastAvailableAt[room] < earlyFreeRoomTime){
                    earlyFreeRoomTime = lastAvailableAt[room];
                    earlyFreeRoom = room;
                }
            }

            // if no free room available, -> delay
            if(!found){
                lastAvailableAt[earlyFreeRoom] += duration;
                roomUsedCount[earlyFreeRoom]++;
            }
        }


        int maxUse = 0;
        int maxUsedRoom = 0;
        for(int i=0; i<n; i++){
            if(roomUsedCount[i] > maxUse){
                maxUse = roomUsedCount[i];
                maxUsedRoom = i;
            }
        }

        return maxUsedRoom;
    }
};