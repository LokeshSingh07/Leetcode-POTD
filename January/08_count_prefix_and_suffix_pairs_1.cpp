// 3042. Count Prefix and Suffix Pairs I

class Solution {
public:
    bool isPrefixSuffix(string str1, string str2){
        int l1 = str1.size();
        int l2 = str2.size();
        if(l1 > l2) return false;

        // check from beginning and ending
        for(int i=0; i<l1; i++){
            if((str1[i] != str2[i]) || (str1[l1-i-1] != str2[l2-i-1])) return false;
        }

        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isPrefixSuffix(words[i], words[j])) count++;
            }
        }

        return count;
    }
};