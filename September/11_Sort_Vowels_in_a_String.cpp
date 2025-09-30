// 2785. Sort Vowels in a String

class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') || ((ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'));
    }

    string sortVowels(string s) {
        string temp = "";
        for(char ch: s){
            if(isVowel(ch)) temp += ch;
        }
        sort(temp.begin(), temp.end());

        int i=0;
        for(auto &ch:s){
            if(isVowel(ch)){
                ch = temp[i];
                i++;
            }
        }

        return s;
    }
};