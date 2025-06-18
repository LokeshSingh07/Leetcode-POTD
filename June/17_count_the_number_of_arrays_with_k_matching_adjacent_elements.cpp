// 3405. Count the Number of Arrays with K Matching Adjacent Elements

int MOD = 1e9+7;
class Solution {
public:
    int findPower(long long a, long long b){
        if(b==0) return 1;

        long long half = findPower(a, b/2);
        long long result = (half*half) % MOD;

        if(b&1){
            result = (result*a) % MOD;
        }

        return result;
    }

    long long nCr(int n, int r, vector<long long> &factorial, vector<long long> &fermatFact){
        return factorial[n] * fermatFact[n-r] % MOD * fermatFact[r] % MOD;
    }

    void factFn(vector<long long> &factorial, int n){
        factorial[0] = factorial[1] = 1;

        for(int i=2; i<=n; i++){
            factorial[i] = (factorial[i-1] * i) % MOD;
        }
    }

    void fermatFn(vector<long long> &fermatFact, vector<long long> &factorial, int n){
        for(int i=0; i<=n; i++){
            fermatFact[i] = findPower(factorial[i], MOD-2);
        }
    }

    int countGoodArrays(int n, int m, int k) {
        vector<long long> factorial(n+1, 1);
        vector<long long> fermatFact(n+1, 1);
        
        factFn(factorial, n);
        fermatFn(fermatFact, factorial, n);

        long long result = nCr(n-1, k, factorial, fermatFact);

        result = (result * m) % MOD;
        result = (result * findPower(m-1, n-k-1)) % MOD;
        return result;
    }
};