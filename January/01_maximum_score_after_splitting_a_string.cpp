// 1422. Maximum Score After Splitting a String

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int ans = 0;

        for(int i=0; i<n-1; i++){
            int countZero=0, countOne=0;
            for(int j=i; j>=0; j--)
                 if(s[j]=='0') countZero++;

            for(int j=i+1; j<n; j++) 
                if(s[j]=='1') countOne++;

            ans = max(ans, countZero+countOne);
        }

        return ans;
    }
};