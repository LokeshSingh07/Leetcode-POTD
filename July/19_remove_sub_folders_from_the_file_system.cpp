// 1233. Remove Sub-Folders from the Filesystem

// Approach-1: (Using Set)
// T.C: O(N * M^2)
// S.C: O(N * M)
class Solution {
public:
    int findLastIndex(string str){
        int n = str.size()-1;
        while(n != 0){
            if(str[n] == '/') return n;
            n--;
        }
        return 0;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> result;
        unordered_set<string> st(begin(folder), end(folder));

        for(auto &fold:folder){
            string temp = fold;
            bool isFound = false;
            while(temp != ""){
                int pos = findLastIndex(temp);
                temp = temp.substr(0, pos);

                if(st.count(temp)){
                    isFound = true;
                    break;
                }
            }

            if(!isFound){
                result.push_back(fold);
            }
        }

        return result;
    }
};


// Approach-2: (sorting)
// T.C: O(N log N + M)
// S.C: O(N)
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder), end(folder));
        vector<string> result;

        for(auto fold: folder){
            if(result.empty()){
                result.push_back(fold);
                continue;
            }

            string temp = result.back();
            temp += '/';
            int pos = temp.size();
            string t = fold.substr(0, pos);
            if(temp != t){
                result.push_back(fold);
            }
        }

        return result;
    }
};