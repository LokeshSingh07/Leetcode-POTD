// 2379. Minimum Recolors to Get K Consecutive Black Blocks

// Method1: two pointer
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0, j=0, count=0;
        int minOp=INT_MAX;

        for(auto ch: blocks){
            if(ch == 'W') count++;
            j++;
            if(j-i == k){
                minOp = min(minOp, count);
                count -= (blocks[i]=='W') ? 1 : 0;
                i++;
            }
        }
        return minOp==INT_MAX ? 0 : minOp;
    }
};