// 2843. Count Symmetric Integers

class Solution {
public:
    int count = 0;
    void checkIsSymmetric(string str){
        int n = str.size();
        if(n & 1) return;
        int firstHalfSum=0, secondHalfSum=0;

        for(int i=0; i<n/2; i++) firstHalfSum += str[i]-'0';
        for(int i=n/2; i<n; i++) secondHalfSum += str[i]-'0';

        if(firstHalfSum == secondHalfSum) count++;
    }

    int countSymmetricIntegers(int low, int high) {

        for(int i=low; i<=high; i++){
            checkIsSymmetric(to_string(i));
        }

        return count;
    }
};