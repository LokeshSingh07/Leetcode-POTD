// 3208. Alternating Groups II

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=0; i<k-1; i++){
            colors.push_back(colors[i]);
        }

        int n=colors.size();
        int i=0, j=1;
        int result = 0;
        while(j<n){
            // alternating tiles of same color
            if(colors[j] == colors[j-1]){
                i=j;
                j++;
                continue;
            }
            if(j-i+1 == k){
                result++;
                i++;
            }
            j++;
        }

        return result;
    }
};