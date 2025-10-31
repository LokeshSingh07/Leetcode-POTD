// 2125. Number of Laser Beams in a Bank

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int totalBeams = 0;
        int prev = 0;

        for(string b: bank){
            int curr = 0;
            for(char ch:b){
                if(ch=='1') curr++;
            }

            if(curr){
                totalBeams += (prev*curr);
                prev = curr;
            }
        }

        return totalBeams;
    }
};