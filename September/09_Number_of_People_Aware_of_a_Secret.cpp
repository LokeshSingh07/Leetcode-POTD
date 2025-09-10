// 2327. Number of People Aware of a Secret

class Solution {
public:
    int MOD = 1e9+7;
    vector<int> t;

    int solve(int day, int delay, int forget){
        if(day == 1) return 1;

        if(t[day] != -1)return t[day];

        int result = 0;
        for(int prev=day-forget+1; prev<=day-delay; prev++){
            if(prev > 0){
                result = (result + solve(prev, delay, forget)) % MOD;
            }
        }
        return t[day] = result;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        t.assign(n+1, -1);
        int total = 0;

        for(int day=n-forget+1; day<=n; day++){
            if(day>0){
                total = (total + solve(day, delay, forget)) % MOD;
            }
        }

        return total;
    }
};