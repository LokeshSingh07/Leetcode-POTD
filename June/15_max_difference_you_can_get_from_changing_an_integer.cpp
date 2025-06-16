// 1432. Max Difference You Can Get From Changing an Integer

class Solution {
public:
    int maxDiff(int num) {
        string str1 = to_string(num);
        string str2 = str1;

        // create maximum number
        int idx = str1.find_first_not_of('9');
        if(idx != string::npos){    // found
            char ch = str1[idx];
            replace(begin(str1), end(str1), ch, '9');
        }

        // create minimum number
        for(int i=0; i<str2.size(); i++){
            char ch = str2[i];
            if(i==0 && ch != '1'){
                replace(begin(str2), end(str2), ch, '1');
                break;
            }
            else if(ch != '0' && ch!=str2[0]){
                replace(begin(str2), end(str2), ch, '0');
                break;
            }
        }

        return stoi(str1) - stoi(str2);
    }
};