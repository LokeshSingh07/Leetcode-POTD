// 1092. Shortest Common Supersequence 

class Solution {
public:
    void SCS(string str1, string str2, int m, int n, vector<vector<int>> &dp){
        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                if(i==0 || j==0){
                    dp[i][j] = i+j;
                }
                else if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));

        SCS(str1, str2, m, n, dp);
        
        int i=m, j=n;
        string result="";
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                result.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] < dp[i][j-1]){
                    result.push_back(str1[i-1]);
                    i--;
                }
                else{
                    result.push_back(str2[j-1]);
                    j--;
                }
            }
        }

        while(i > 0){
            result.push_back(str1[i-1]);
            i--;
        } 
        while(j > 0){
            result.push_back(str2[j-1]);
            j--;
        }

        reverse(begin(result), end(result));
        return result;
    }
};