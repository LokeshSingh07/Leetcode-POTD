// 3394. Check if Grid can be Cut into Sections

class Solution {
public:
    void mergeInterval(vector<vector<int>>& intervals, vector<vector<int>> &result){
        sort(begin(intervals), end(intervals));
        int n = intervals.size();
        result.push_back(intervals[0]);

        for(int i=1; i<n; i++){
            if(result.back()[1] > intervals[i][0]){
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> Xaxis;
        vector<vector<int>> Yaxis;

        for(int i=0; i<rectangles.size(); i++){
            int x1 = rectangles[i][0]; 
            int y1 = rectangles[i][2];
            int x2 = rectangles[i][1]; 
            int y2 = rectangles[i][3];
            Xaxis.push_back({x1,y1});
            Yaxis.push_back({x2,y2});
        }

        vector<vector<int>> result1;
        vector<vector<int>> result2;
        mergeInterval(Xaxis, result1);
        mergeInterval(Yaxis, result2);

        return result1.size()>=3 || result2.size()>=3;
    }
};