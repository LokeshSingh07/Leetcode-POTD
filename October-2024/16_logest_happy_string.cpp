// 1405. Longest Happy String

class Solution {
public:
    typedef pair<int, char> P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P, vector<P>> pq;    // maxHeap
        string result = "";

        if(a>0) pq.push({a, 'a'});
        if(b>0) pq.push({b, 'b'});
        if(c>0) pq.push({c, 'c'});

        while(!pq.empty()){
            int currCnt = pq.top().first;
            int currChar = pq.top().second;
            pq.pop();

            // check 
            if(result.length()>1 && result[result.length()-1] == currChar && result[result.length()-2] == currChar){
                if(pq.empty()) break;       // catch

                int nextCnt = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();

                result.push_back(nextChar);
                nextCnt--;
                if(nextCnt > 0) pq.push({nextCnt, nextChar});
            }
            else{
                result.push_back(currChar);
                currCnt--;
            }

            if(currCnt > 0) pq.push({currCnt, currChar});
        }

        return result;
    }
};