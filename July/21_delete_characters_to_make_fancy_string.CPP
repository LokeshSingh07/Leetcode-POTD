// 1957. Delete Characters to Make Fancy String

class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string result = "";
        result.push_back(s[0]);
        int count=1;

        for(int i=1; i<n; i++){
            if(result.back() == s[i]){
                if(count < 2) result.push_back(s[i]);
                count++;
            }
            else{
                result.push_back(s[i]);
                count = 1;
            }
        }

        return result;
    }
};