// 165. Compare Version Numbers

class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1);
        stringstream ss2(version2);
        string token1="", token2="";
    
        while(ss1.good() || ss2.good()){
            if(!getline(ss1, token1, '.')) token1 = '0';
            if(!getline(ss2, token2, '.')) token2 = '0';
            int a = stoi(token1);
            int b = stoi(token2);

            if(a < b) return -1;
            if(a > b) return 1;
        }

        return 0;
    }
};