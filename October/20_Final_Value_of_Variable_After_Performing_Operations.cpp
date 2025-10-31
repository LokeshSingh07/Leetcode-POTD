// 2011. Final Value of Variable After Performing Operations

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(operations[i] == "X--" || operations[i] == "--X") cnt--;
            else cnt++;
        }

        return cnt;
    }
};