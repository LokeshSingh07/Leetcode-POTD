// 3494. Find the Minimum Amount of Time to Brew Potions

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> finishTime(n,0);

        for(int i=0; i<m; i++){
            finishTime[0] += 1LL * mana[i] * skill[0];

            for(int j=1; j<n; j++){
                finishTime[j] = max(finishTime[j], finishTime[j-1]) + (1LL * mana[i] * skill[j]);
            }

            // sync of time
            for(int j=n-1; j>0; j--){
                finishTime[j-1] = finishTime[j] - 1LL * mana[i] * skill[j];
            }
        }

        return finishTime[n-1];
    }
};