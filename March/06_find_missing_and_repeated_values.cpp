// 2965. Find Missing and Repeated Values

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans(2);
        unordered_map<int,int> mp;
        int totalSum = 0;
        int sum = n*n*((n*n)+1)/2;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mp[grid[i][j]]++;
                totalSum += grid[i][j];
            }
        }
        cout<<totalSum<<" , "<<sum;

        for(auto it: mp){
            if(it.second > 1){
                ans[0] = it.first;
                ans[1] = sum - (totalSum-it.first);
                break;
            }
        }   

        return ans;
    }
};