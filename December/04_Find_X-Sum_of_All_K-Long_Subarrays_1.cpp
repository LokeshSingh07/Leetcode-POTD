// 3318. Find X-Sum of All K-Long Subarrays I

class Solution {
public:
    typedef pair<int,int> P;
    int solve(unordered_map<int,int> &mp, int &x){
        int sum = 0;
        priority_queue<P, vector<P>, greater<P>> pq;

        for(auto &it: mp){
            pq.push({it.second, it.first});

            if(pq.size() > x) pq.pop();
        }

        while(!pq.empty()){
            auto [freq, val] = pq.top();
            pq.pop();

            sum += val*freq;
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int,int> mp;
        int i=0, j=0;

        while(j<n){
            mp[nums[j]]++;

            if(j-i+1 == k){
                int ans = solve(mp, x);
                result.push_back(ans);

                int ele = nums[i];
                mp[ele]--;
                if(mp[ele] == 0) mp.erase(ele);
                i++; 
            }
            j++;
        }

        return result;
    }
};