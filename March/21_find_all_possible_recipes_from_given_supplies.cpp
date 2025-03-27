// 2115. Find All Possible Recipes from Given Supplies

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> suppliesSt;
        vector<string> ans;

        for(auto s: supplies){
            suppliesSt.insert(s); 
        }

        int n = recipes.size();
        int count = n;
        vector<bool> cooked(n,false); 
        while(count--){
            for(int i=0; i<n; i++){
                if(cooked[i] == true) continue;

                string re = recipes[i];
                bool flag = true;
                for(int j=0; j<ingredients[i].size(); j++){
                    string ing = ingredients[i][j];
                    if(!suppliesSt.count(ing)){
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    suppliesSt.insert(re);
                    ans.push_back(re);
                    cooked[i] = true;
                }
            }
        }
    
        return ans;
    }
};