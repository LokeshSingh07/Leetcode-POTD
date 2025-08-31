// 36. Valid Sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;

                int idx = (i/3)*3 + j/3;
                char ch = board[i][j];
                if(rows[i].count(ch) || cols[j].count(ch) || boxes[idx].count(ch)) return false;
                rows[i].insert(ch);
                cols[j].insert(ch);
                boxes[idx].insert(ch);
            }
        }

        return true;
    }
};