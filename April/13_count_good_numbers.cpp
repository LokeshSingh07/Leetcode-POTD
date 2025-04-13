// 1922. Count Good Numbers

class Solution {
public:
    const int MOD = 1e9+7;
    int fastExpo(long long a, long long b){
        if(b==0) return 1;

        long long val = fastExpo(a, b/2);
        long long result = (val * val) % MOD;
        if(b & 1) result = (result * a) % MOD;

        return result;
    }

    int countGoodNumbers(long long n) {
        return ((1LL) * fastExpo(5, (n+1)/2) * fastExpo(4, n/2)) % MOD;
    }
};