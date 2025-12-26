// 3228. Maximum Number of Operations to Move Ones to the End

class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int i=0;
        int result = 0;
        int seen1Count = 0;

        while(i < n){
            if(s[i] == '0'){
                result += seen1Count;
                while(i<n && s[i]=='0') i++;
            }
            else{
                seen1Count++;
                i++;
            }
        }

        return result;
    }
};