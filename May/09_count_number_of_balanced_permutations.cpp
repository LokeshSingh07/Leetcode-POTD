// 3343. Count Number of Balanced Permutations

class Solution {
public:
    int M = 1e9+7;
    int n;
    int totalDigitSum;
    int totalPermPossible = 0;

    // Binary expon
    int findPower(long long a, long long b){
        if(b==0) return 1;

        long long half = findPower(a, b/2);
        long long result = (half * half) % M;
        if(b%2){
            result = (result * a) % M;
        }
        return result;
    }

    long long solve(int digit, int evenIndexDigitSum, int currSum, vector<int> &freq, vector<long long> &fermatFact, vector<vector<vector<long long>>> &dp){
        if(digit == 10){
            if(currSum == totalDigitSum/2 && evenIndexDigitSum == (n+1)/2){
                return totalPermPossible;
            }
            return 0;
        }

        if(dp[digit][evenIndexDigitSum][currSum] != -1){
            return dp[digit][evenIndexDigitSum][currSum];
        }

        long long ways = 0;
        for(int count=0; count<=min(freq[digit], (n+1)/2 - evenIndexDigitSum); count++){
            int evenPosCount = count;
            int oddPosCount = freq[digit] - count;

            long long div = (fermatFact[evenPosCount] * fermatFact[oddPosCount]) % M;
            long long val = solve(digit+1, evenIndexDigitSum + evenPosCount, currSum + digit*count, freq, fermatFact, dp);
            ways = (ways + (div * val) % M) % M;
        }

        return dp[digit][evenIndexDigitSum][currSum] = ways;
    }

    int countBalancedPermutations(string num) {
        n = num.size();
        totalDigitSum = 0;

        vector<int> freq(10, 0);
        for(int i=0; i<n; i++){
            totalDigitSum += num[i] - '0';
            freq[num[i]-'0']++; 
        }

        if(totalDigitSum % 2 != 0){
            return 0;
        }

        // precompute factorial
        vector<long long> fact(n+1, 1);
        fact[0] = 1;
        fact[1] = 1;
        for(int i=2; i<=n; i++){
            fact[i] = (fact[i-1] * i) % M;
        }

        // precompute fermatFactorial
        vector<long long> fermatFact(n+1, 1);
        for(int i=0; i<=n; i++){
            fermatFact[i] = findPower(fact[i], M-2) % M;
        }

        totalPermPossible = (1LL * fact[(n+1)/2] * fact[n/2]) % M;
        int digit=0;
        int evenIdexDigitsCount=0;
        int currSum = 0;
        vector<vector<vector<long long>>> dp(10, vector<vector<long long>>((n+1)/2 + 1 , vector<long long>(totalDigitSum+1, -1)));
        return solve(digit, evenIdexDigitsCount, currSum, freq, fermatFact, dp);
    }
};