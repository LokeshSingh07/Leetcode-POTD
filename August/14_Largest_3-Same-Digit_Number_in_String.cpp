// 2264. Largest 3-Same-Digit Number in String

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string result = "";

        for(int i=0; i<n-2; i++){
            string temp = num.substr(i, 3);
            if(num[i]==num[i+1] && num[i]==num[i+2] && temp > result){
                result = temp;
            }
        }

        return result;
    }
};

