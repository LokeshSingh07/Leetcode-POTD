// 2147. Number of Ways to Divide a Long Corridor

class Solution {
public:
    int M = 1e9+7;

    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<int> seats;

        for(int i=0; i<n; i++){
            if(corridor[i] == 'S')
                seats.push_back(i);
        }

        if(seats.size() % 2 != 0 || seats.size() == 0) return 0;

        long long result = 1;
        int prev = seats[1];

        for(int i=2; i<seats.size(); i+=2){
            int length = seats[i] - prev;
            result = (result * length) % M;
            prev = seats[i+1];
        }

        return result;
    }
};