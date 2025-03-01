// 1079. Letter Tile Possibilities

class Solution {
public:
    void solve(string tiles, unordered_set<string> &result, vector<bool> &used, string curr){
        result.insert(curr);

        for(int i=0; i<tiles.size(); i++){
            if(used[i] == true) continue;

            curr.push_back(tiles[i]);
            used[i] = true;
            solve(tiles, result, used, curr);

            // backtarck
            curr.pop_back();
            used[i] = false;
        }
    }

    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<bool> used(n, false);
        unordered_set<string> result;
        solve(tiles, result, used, "");

        return result.size()-1;
    }
};