// 2116. Check if a Parentheses String Can Be Valid

class Solution {
public:
    bool canBeValid(string s, string locked){
        int n = s.size();
        if(n & 1) return false;
        int openCount=0, closedCount=0;

        // step1: Left to Rigth
        for(int i=0; i<n; i++){
            if(locked[i] == '0' || s[i] == '(') openCount++;
            else openCount--;
            
            if(openCount < 0) return false;     // catch
        }

        // Right to left
        for(int i=n-1; i>=0; i--){
            if(locked[i] == '0' || s[i] == ')') closedCount++;
            else closedCount--;

            if(closedCount < 0) return false;   // catch
        }   

        return true;
    }
};