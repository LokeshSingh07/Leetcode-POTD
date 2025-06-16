// 3362. Zero Array Transformation III

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int Q = queries.size();

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        sort(begin(queries), end(queries));

        int j = 0;
        int usedCount = 0;

        for(int i=0; i<n; i++){
            while(j < Q && queries[j][0] == i){
                maxHeap.push(queries[j][1]);
                j++;
            }

            nums[i] -= minHeap.size();

            while(nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i){
                int ending = maxHeap.top();
                maxHeap.pop();
                minHeap.push(ending);
                usedCount++;
                nums[i]--;
            }

            if(nums[i] > 0) return -1;
        
            while(!minHeap.empty() && minHeap.top() <= i){
                minHeap.pop();
            }
        }

        return Q - usedCount;
    }
};