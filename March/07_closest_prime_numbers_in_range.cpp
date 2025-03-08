// 2523. Closest Prime Numbers in Range

class Solution {
public:
    void sieve(int right, vector<bool> &isPrime){
        isPrime[0] = isPrime[1] = false;

        for(int i=2; i*i<=right; i++){
            if(isPrime[i]){
                for(int j=i*i; j<=right; j+=i){
                    isPrime[j] = false;
                }
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right+1, true);
        sieve(right, isPrime);

        vector<int> primes;
        for(int i=left; i<=right; i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }
    
        // find minimum diff
        vector<int> ans = {-1, -1};
        int minDiff = INT_MAX; 
        for(int i=1; i<primes.size(); i++){
            if(minDiff > (primes[i]-primes[i-1])){
                ans = {primes[i-1], primes[i]};
                minDiff = primes[i]-primes[i-1];
            }
        }

        return ans;
    }
};