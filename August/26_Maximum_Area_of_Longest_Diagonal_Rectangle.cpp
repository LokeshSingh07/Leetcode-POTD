// 3000. Maximum Area of Longest Diagonal Rectangle

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int result = 0;
        int lonDia = 0;

        for(auto dim: dimensions){
            int l = dim[0];
            int b = dim[1];
            int diagonal = l*l + b*b;
            if(diagonal > lonDia){
                lonDia = diagonal;
                result = l*b;
            }else if(diagonal == lonDia){
                result = max(result, l*b);
            }
        }

        return result;
    }
};