// 73. Set Matrix Zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        set<int> row;
        set<int> col;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
    
    
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(row.count(i) || col.count(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    
    }
};