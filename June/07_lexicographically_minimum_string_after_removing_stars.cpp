// 3170. Lexicographically Minimum String After Removing Stars

class Solution {
public:
    typedef pair<char,int> P;

    struct comp{
        bool operator()(P &p1, P &p2){
            if(p1.first == p2.first){
                return p1.second < p2.second;
            }
            return p1.first > p2.first;    
        }
    };

    string clearStars(string s) {
        int n = s.size();
        priority_queue<P, vector<P>, comp> minHeap;

        for(int i=0; i<n; i++){
            if(s[i] != '*') minHeap.push({s[i], i});
            else{
                int idx = minHeap.top().second;
                minHeap.pop();
                s[idx] = '*';
            }
        }

        string result = "";
        for(int i=0; i<n; i++){
            if(s[i] != '*'){
                result.push_back(s[i]);
            }
        }

        return result;
    }
};