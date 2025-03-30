// 2818. Apply Operations to Maximize Score

class Solution {
public:
    const int MOD = 1e9 + 7;
    long long findPower(long long a, long long b){
        if(b==0) return 1;

        long long half = findPower(a, b/2);
        long long result = (half * half) % MOD;
        if(b%2 == 1){
            result = (result*a) % MOD;
        }
        return result;
    }

    vector<int> getPrimes(int limit){
        vector<bool> isPrime(limit+1, true);
        vector<int> primes;

        for(int i=2; i*i<=limit; i++){
            if(isPrime[i]){
                for(int j=i*i; j<=limit; j+=i){
                    isPrime[j] = false;
                }
            }
        }

        for(int i=2; i<=limit; i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }

        return primes;
    }

    vector<int> findPrimeScores(vector<int> &nums){
        int n = nums.size();
        vector<int> primeScores(n,0);
        int maxi = *max_element(begin(nums), end(nums));
        vector<int> primes = getPrimes(maxi);

        for(int i=0; i<n; i++){
            int num = nums[i];

            for(int prime: primes){
                if(prime*prime > num) break;
                if(num % prime != 0) continue;

                primeScores[i]++;
                while(num % prime == 0){
                    num /= prime;
                }
            }
            if(num > 1){
                primeScores[i]++;
            }
        }

        return primeScores;
    }

    vector<int> findNextGreator(vector<int> &primeScores){
        int n = primeScores.size();
        stack<int> st;
        vector<int> nextGreator(n, n);

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && primeScores[st.top()] <= primeScores[i]){
                st.pop();
            }

            nextGreator[i] = st.empty() ? n : st.top();
            st.push(i); 
        }

        return nextGreator;
    }

    vector<int> findPrevGreator(vector<int> &primeScores){
        int n = primeScores.size();
        stack<int> st;
        vector<int> prevGreator(n, -1);

        for(int i=0; i<n; i++){
            while(!st.empty() && primeScores[st.top()] < primeScores[i]){
                st.pop();
            }

            prevGreator[i] = st.empty() ? -1 : st.top();
            st.push(i); 
        }

        return prevGreator;
    }

    int maximumScore(vector<int>& nums, int k) {
        vector<int> primeScores = findPrimeScores(nums);
        vector<int> nextGreator = findNextGreator(primeScores);
        vector<int> prevGreator = findPrevGreator(primeScores);

        // calculate subarray
        int n = nums.size();
        vector<long long> subArrays(n, 0);
        for(int i=0; i<n; i++){
            subArrays[i] = (long long)(nextGreator[i] - i) * (i - prevGreator[i]);
        }

        // sort {subarray,idx}
        vector<pair<long long,int>> sortedNums(n);
        for(int i=0; i<n; i++){
            sortedNums[i] = {nums[i], i};
        }

        sort(begin(sortedNums), end(sortedNums), greater<>());

        // calculate score
        long long score = 1;
        int idx = 0;
        while(k > 0){
            auto [num, i] = sortedNums[idx];
            long long operations = min((long long)k, subArrays[i]);
            score = (score * findPower(num, operations)) % MOD;
            k -= operations;
            idx++;
        }

        return score;
    }
};