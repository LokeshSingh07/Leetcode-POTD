// 2999. Count the Number of Powerful Integers

class Solution {
public:
    long long solve(string str, string suff, int limit){
        long long count = 0;
        long long remainLen = str.length() - suff.length();
        
        if(remainLen < 0) return 0;
        string trailString = str.substr(remainLen);

        for(int i=0; i<remainLen; i++){
            int digit = str[i] - '0';
            if(digit <= limit) {
                count += digit * pow(limit+1, remainLen-i-1);
            }
            else {
                count += pow(limit+1, remainLen-i); 
                return count;
            }
        }
        if(trailString >= suff) count++;

        return count;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start-1);
        string endStr = to_string(finish);

        return solve(endStr, s, limit) - solve(startStr, s, limit);

    }
};