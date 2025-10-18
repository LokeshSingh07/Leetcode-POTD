// 2300. Successful Pairs of Spells and Potions

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        int n = potions.size();

        sort(begin(potions), end(potions));
        int maxPotionValue = potions[n-1];
        vector<int> ans;

        for(int i=0; i<m; i++){
            int spell = spells[i];

            long long minPotion = ceil((1.0*success)/spell);

            if(minPotion > maxPotionValue){
                ans.push_back(0);
                continue;
            }

            int index = lower_bound(begin(potions), end(potions), minPotion) - begin(potions);
            int count = n-index;
            ans.push_back(count);
        }

        return ans;
    }
};