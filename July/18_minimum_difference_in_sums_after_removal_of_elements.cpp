// 2163. Minimum Difference in Sums After Removal of Elements


// Approach-1: (heap + sliding window)
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N/3;

        vector<long long> leftSum(N, 0);
        vector<long long> rightSum(N, 0);
        
        long long currSum = 0;
        priority_queue<int> maxHeap; 
        for(int i=0; i<2*n; i++){
            maxHeap.push(nums[i]);
            currSum += nums[i];

            if(maxHeap.size() > n){
                currSum -= maxHeap.top();
                maxHeap.pop();
            }

            leftSum[i] = currSum;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        currSum=0;
        for(int i=N-1; i>=n; i--){
            currSum += nums[i];
            minHeap.push(nums[i]);

            if(minHeap.size() > n){
                currSum -= minHeap.top();
                minHeap.pop();
            }

            rightSum[i] = currSum;
        }

        long long result = LLONG_MAX;
        for(int i=n-1; i<2*n; i++){
            result = min(result, leftSum[i]-rightSum[i+1]);
        }

        return result;
    }
};