// 498. Diagonal Traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        map<int,vector<int>> mp;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        vector<int> result;
        for(auto &it: mp){
            if(!(it.first & 1)){
                reverse(begin(it.second), end(it.second));
            }

            for(int i=0; i<it.second.size(); i++){
                result.push_back(it.second[i]);
            }
        }
        return result;
    }
};