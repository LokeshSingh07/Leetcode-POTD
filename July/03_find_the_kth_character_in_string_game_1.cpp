// 3304. Find the K-th Character in String Game I

class Solution {
public:
    char kthCharacter(int k) {
        string str = "a";

        while(str.size() < k){
            int n = str.size();
            for(int i=0; i<n; i++){
                char ch = (str[i] == 'z') ? 'a' : str[i]+1;
                str.push_back(ch);
            }
        }

        return str[k-1];
    }
};