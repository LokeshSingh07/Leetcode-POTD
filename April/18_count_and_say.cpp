// 38. Count and Say

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string say = countAndSay(n-1);

        // precprocessing
        string result = "";
        int len = say.size();
        int i=0;
        while(i<len){
            char ch = say[i];
            int count = 1;
            while(i<len-1 && say[i]==say[i+1]){
                count++;
                i++;
            }

            result += to_string(count) + ch;
            i++;
        }

        return result;
    }
};