// 3477. Fruits Into Baskets II

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int result=0;


        for(auto fruit : fruits){
            bool placed = false;
            for(int j=0; j<n; j++){
                if(fruit <= baskets[j]){
                    placed = true;
                    baskets[j] = -1;
                    break;
                }
            }

            if(!placed) result++;
        }

        return result;
    }
};