// 781. Rabbits in Forest

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int,int> mp;

        for(auto it:answers){
            mp[it]++;
        }

        int total = 0;
        for(auto it: mp){
            int x = it.first;
            int count = it.second;
            int  groups = (count+x)/(x+1);
            total += groups * (x+1);
        }

        return total;
    }
};