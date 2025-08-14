// 2106. Maximum Fruits Harvested After at Most K Steps

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> prefSum(n, 0);
        vector<int> position(n, 0);

        for(int i=0; i<n; i++){
            position[i] = fruits[i][0];
            prefSum[i] = fruits[i][1] + (i>0 ? prefSum[i-1] : 0);
        }

        int maxFruits = 0;
        for(int d=0; d<=k/2; d++){
            // from P -> left -> right
            int i = startPos - d;
            int j = startPos + (k-2*d);
            int left = lower_bound(begin(position), end(position), i) - begin(position);  
            int right = (upper_bound(begin(position), end(position), j) - begin(position)) - 1;
            
            if(left <= right){
                int total = prefSum[right] - (left>0 ? prefSum[left-1] : 0);
                maxFruits = max(maxFruits, total);
            }

            // from P -> right -> left
            j = startPos + d;
            i = startPos - (k-2*d);
            left = lower_bound(begin(position), end(position), i) - begin(position);  
            right = (upper_bound(begin(position), end(position), j) - begin(position)) - 1;
            
            if(left <= right){
                int total = prefSum[right] - (left>0 ? prefSum[left-1] : 0);
                maxFruits = max(maxFruits, total);
            }
        }

        return maxFruits;
    }
};