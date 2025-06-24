// 3443. Maximum Manhattan Distance After K Changes

class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int east = 0;
        int west = 0;
        int north = 0;
        int south = 0;
        int maxMD = 0;

        for(int i=0; i<n; i++){
            if(s[i] == 'E') east++;
            else if(s[i] == 'W') west++;
            else if(s[i] == 'N') north++;
            else south++;

            int currMD = abs(east-west) + abs(north-south);
            
            int steps = i+1;
            int wastageSteps = steps - currMD;
            int extraSteps = 0;
            if(steps != currMD){
                extraSteps = min(wastageSteps, 2*k);
            }

            currMD += extraSteps;

            maxMD = max(maxMD, currMD);
        }

        return maxMD;
    }
};