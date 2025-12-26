// 944. Delete Columns to Make Sorted

class Solution {
    public int minDeletionSize(String[] strs) {
        int m = strs.length;
        int n = strs[0].length();
        int result = 0;

        for(int j=0; j<n; j++){
            for(int i=1; i<m; i++){
                if(strs[i-1].charAt(j) > strs[i].charAt(j)){
                    result++;
                    break;
                };
            }
        }

        return result;
    }
}