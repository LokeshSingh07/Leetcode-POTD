// 838. Push Dominoes

class Solution {
public:
    string pushDominoes(string dominoes) {
        int  n = dominoes.size();
        vector<int> leftClosestR(n,-1);
        vector<int> rightClosestL(n,-1);
        
        for(int i=0; i<n; i++){
            char ch = dominoes[i];
            if(ch == 'L'){
                leftClosestR[i] = -1;
            }
            else if(ch == 'R'){
                leftClosestR[i] = i;
            }
            else if(i>0 && ch == '.'){
                leftClosestR[i] = leftClosestR[i-1];
            }
        }

        for(int i=n-1; i>=0; i--){
            char ch = dominoes[i];
            if(ch == 'L'){
                rightClosestL[i] = i;
            }
            else if(ch == 'R'){
                rightClosestL[i] = -1;;
            }
            else if(i<n-1 && ch == '.'){
                rightClosestL[i] = rightClosestL[i+1];
            }
        }
    

        string result = "";
        for(int i=0; i<n; i++){
            int distLeftR = abs(i - leftClosestR[i]);
            int distRightL = abs(i - rightClosestL[i]);
            
            if(leftClosestR[i] == rightClosestL[i]){
                result.push_back('.');
            }
            else if(leftClosestR[i] == -1){
                result.push_back('L');
            }
            else if(rightClosestL[i] == -1){
                result.push_back('R');
            }
            else if(distLeftR == distRightL){
                result.push_back('.');
            }
            else{
                result.push_back(distLeftR < distRightL ? 'R' : 'L');
            }
        }

        return result;
    }
};