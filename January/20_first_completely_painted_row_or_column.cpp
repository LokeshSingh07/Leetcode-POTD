// 2661. First Completely Painted Row or Column

class Solution {
public:
    int m,n;

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        unordered_map<int, pair<int,int>> mp;

        // store it in map
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[mat[i][j]] = {i,j};  
            }
        }

        // keep track of every row & col painted
        vector<int> rowPainted(m,0), colPainted(n,0);

        for(int i=0; i<arr.size(); i++){
            int val = arr[i];
            auto P = mp[val];

            rowPainted[P.first]++;
            colPainted[P.second]++;

            // if(check(rowPainted, colPainted)) return i;
            if(rowPainted[P.first]==n || colPainted[P.second]==m) return i;
        }

        return -1;
    }
};