// 3136. Valid Word

class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if(n < 3) return false;

        bool vow=false, cons=false;
        for(auto ch: word){
            if(isalpha(ch)){
                ch = tolower(ch);
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') vow = true;
                else cons = true;
            }
            else if(!isdigit(ch)) return false;
        }

        return (vow && cons);
    }
};