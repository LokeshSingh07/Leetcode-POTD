// 3337. Total Characters in String After Transformations II

class Solution {
public:
    typedef vector<vector<int>> Matrix;
    int MOD = 1e9+7;

    Matrix matrixMultiplication(const Matrix &A, const Matrix &B){
        Matrix result(26, vector<int>(26, 0));

        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                for(int k=0; k<26; k++){
                    result[i][j] = (result[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;
                }
            }
        }
        return result;
    }

    Matrix matrixExponentiation(const Matrix &base, int exp){
        if(exp==0){
            Matrix identity (26, vector<int>(26,0));
            for(int i=0; i<26; i++){
                identity[i][i] = 1;
            }
            return identity;
        }


        Matrix half = matrixExponentiation(base, exp/2);
        Matrix result = matrixMultiplication(half, half);

        if(exp % 2 == 1){
            result = matrixMultiplication(result, base);
        }
        return result;
    }


    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<int> freq(26,0);
        for(char &ch: s){
            freq[ch-'a']++;
        }

        Matrix T(26, vector<int>(26,0));
        for(int i=0; i <26; i++){
            for(int add=1; add<=nums[i]; add++){
                T[(i+add)%26][i]++;
            }
        }

        Matrix result = matrixExponentiation(T, t);

        vector<int> updated_freq(26,0);
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                updated_freq[i] = (updated_freq[i] + (1LL * result[i][j] * freq[j]) % MOD) % MOD;
            }
        }

        int resultLen = 0;
        for(int i=0; i<26; i++){
            resultLen = (resultLen + updated_freq[i]) % MOD;
        }

        return resultLen;
    }
};