// 1128. Number of Equivalent Domino Pairs


class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        int result = 0;

        for(int i=0; i<n-1; i++){
            if(dominoes[i][0] > dominoes[i][1]){
                swap(dominoes[i][0], dominoes[i][1]);
            }
            for(int j=i+1; j<n; j++){
                if(dominoes[j][0] > dominoes[j][1]){
                    swap(dominoes[j][0], dominoes[j][1]);
                } 
                if((dominoes[i][0] == dominoes[j][0]) && (dominoes[i][1] == dominoes[j][1])){
                    result++;
                }
            }
        }
        return result;
    }
};


class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> num(100);
        int ret = 0;

        for(auto &it: dominoes){
            int val = it[0] < it[1] ? it[0]*10+it[1] : it[1]*10+it[0];
            ret += num[val];
            num[val]++;
        }

        return ret;
    }
};