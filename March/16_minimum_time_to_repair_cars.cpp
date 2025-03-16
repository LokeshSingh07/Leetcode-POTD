// 2594. Minimum Time to Repair Cars

class Solution {
public:
    bool isPossible(vector<int>&ranks, int cars, long long mid){
        long long carRepaired = 0;

        for(int i=0; i<ranks.size(); i++){
            carRepaired += sqrt(mid/ranks[i]);
            if(carRepaired >= cars) return true;
        }

        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long s=0;
        long long mini = *min_element(begin(ranks), end(ranks));;
        long long e = mini*cars*cars;
        long long result = 0;

        while(s <= e){
            long long mid = s+(e-s)/2;
            if(isPossible(ranks, cars, mid)){
                result = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }


        return result;
    }
};