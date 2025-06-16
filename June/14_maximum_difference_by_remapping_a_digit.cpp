// 2566. Maximum Difference by Remapping a Digit

class Solution {
public:
    int minMaxDifference(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        string maxiNum, miniNum;
        char firstCharNotNine = '\0';

        for(char &ch: numStr){
            if(ch == '9') continue;
            firstCharNotNine = ch;
            break;
        }

        if(firstCharNotNine == '\0') return num;

        // create maximum num
        maxiNum = numStr;
        for(char &ch: maxiNum){
            if(ch == firstCharNotNine){
                ch = '9';
            }
        }

        // create minimum num
        char firstChar = numStr[0];
        miniNum = numStr;
        for(char &ch: miniNum){
            if(ch == firstChar){
                ch = '0';
            }
        }


        return stoi(maxiNum) - stoi(miniNum);
    }
};