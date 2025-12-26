// 3531. Count Covered Buildings

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> topRow(n+1);
        vector<int> bottomRow(n+1, n+1);
        vector<int> leftCol(n+1, n+1);
        vector<int> rightCol(n+1);

        for(auto &P : buildings){
            int x=P[0], y=P[1];

            topRow[y] = max(topRow[y], x);
            bottomRow[y] = min(bottomRow[y], x);
            rightCol[x] = max(rightCol[x], y);
            leftCol[x] = min(leftCol[x], y); 
        }

        int result = 0;
        for(auto &P : buildings){
            int x=P[0], y=P[1];
            if(x > bottomRow[y] && x<topRow[y] && y>leftCol[x] && y<rightCol[x]){
                result++;
            }
        }

        return result;
    }
};