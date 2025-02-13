// 3066. Minimum Operations to Exceed Threshold Value II

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n =nums.size();
        int minOperation  = 0;
        priority_queue<long, vector<long>, greater<long>> pq(begin(nums), end(nums));  // min-Heap

        while(pq.size() > 1 && pq.top() < k){
            long v1 = pq.top();
            pq.pop();
            long v2 = pq.top();
            pq.pop();

            long res = v1*2 + v2;
            pq.push(res);
            minOperation++;
        }
  
        return minOperation;
    }
};