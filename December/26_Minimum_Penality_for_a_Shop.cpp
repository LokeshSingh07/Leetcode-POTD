// 2483. Minimum Penalty for a Shop

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int prefix = 0;
        int minPenality = 0;
        int bestTime = 0;

        for(int i=0; i<n; i++){
            prefix += (customers[i] == 'Y' ? -1 : 1);

            if(prefix < minPenality){
                minPenality = prefix;
                bestTime = i+1;
            }
        }

        return bestTime;
    }
};