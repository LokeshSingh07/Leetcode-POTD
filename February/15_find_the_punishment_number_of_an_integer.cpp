// 2698. Find the Punishment Number of an Integer

class Solution {
public:
    bool check(int i, int currSum, string s, int target){
        if(i==s.length()) return currSum==target;
        if(currSum > target) return false;

        bool possible = false;
        for(int j=i; j<s.length(); j++){
            string sub = s.substr(i, j-i+1);
            int val = stoi(sub);

            possible = possible || check(j+1, currSum+val, s, target);
            if(possible) return true;
        }

        return possible;
    }

    int punishmentNumber(int n) {
        int punish = 0;

        for(int num=1; num<=n; num++){
            int sq = num*num;
            string s = to_string(sq);
            
            if(check(0, 0, s, num)) punish += sq;
        }

        return punish;
    }
};