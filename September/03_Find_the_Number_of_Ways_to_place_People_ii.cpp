// 3027. Find the Number of Ways to Place People II

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;

        auto lambda = [](vector<int> &p1, vector<int> &p2){
            if(p1[0]==p2[0]) return p1[1] > p2[1];
            return p1[0] < p2[0];
        };

        sort(begin(points), end(points), lambda);

        for(int i=0; i<n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            int maxY = INT_MIN;
            for(int j=i+1; j<n; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(y2 > y1) continue;

                if(y2 > maxY){
                    result++;
                    maxY = y2;
                }
            }
        }

        return result;
    }
};