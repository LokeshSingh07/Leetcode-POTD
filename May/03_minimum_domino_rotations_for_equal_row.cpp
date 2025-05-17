// 1007. Minimum Domino Rotations For Equal Row

class Solution {
public:
    int find(vector<int> &tops, vector<int> &bottoms, int val){
        int n = tops.size();
        int topSwaps=0, bottomSwaps=0;;

        for(int i=0; i<n; i++){
            if(tops[i] != val && bottoms[i] != val) return -1;
            if(tops[i] != val) bottomSwaps++;
            if(bottoms[i] != val) topSwaps++;
        }

        return min(topSwaps, bottomSwaps);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = INT_MAX;

        for(int i=1; i<=6; i++){
            int temp = find(tops, bottoms, i);

            if(temp != -1){
                result = min(result, temp);
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};