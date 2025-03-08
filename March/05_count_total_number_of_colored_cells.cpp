// 2579. Count Total Number of Colored Cells

class Solution {
public:
    long long coloredCells(int n) {
        long long  noOfBlueCells = 1;
        long long append = 4;

        while(--n){
            noOfBlueCells += append;
            append += 4;
        }

        return noOfBlueCells;
    }
};