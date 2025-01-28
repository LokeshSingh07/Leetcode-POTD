// 2948. Make Lexicographically Smallest Array by Swapping Elements

// Method1: TLE
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        for(int i=0; i<n; i++){
            while(1){
                int smallestValue = nums[i];
                int idx = -1;
                for(int j=i+1; j<n; j++){
                    if(abs(nums[j] - nums[i]) <= limit){
                        if(nums[j] < smallestValue){
                            smallestValue = nums[j];
                            idx = j;
                        }
                    }
                }

                if(idx != -1) swap(nums[i], nums[idx]);
                else break;
            }
        }

        return nums;
    }
};


// Methdo2: map
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> vec = nums;
        sort(begin(vec), end(vec));

        int groupNum = 0;
        unordered_map<int, deque<int>> groupToList;
        groupToList[0].push_back(vec[0]);

        unordered_map<int,int> numToGroup;
        numToGroup[vec[0]] = 0;

        for(int i=1; i<n; i++){
            if(vec[i] - vec[i-1] > limit) groupNum++;

            numToGroup[vec[i]] = groupNum;
            groupToList[groupNum].push_back(vec[i]); 
        }

        // build answer
        vector<int> res(n);
        for(int i=0; i<n; i++){
            int group = numToGroup[nums[i]];

            res[i] = groupToList[group].front();
            groupToList[group].pop_front();
        }

        return res;
    }
};