// 2071. Maximum Number of Tasks You Can Assign

class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid){
        int pillUsed = 0;
        multiset<int> st(begin(workers), begin(workers)+mid);

        for(int i=mid-1; i>=0; i--){
            int required = tasks[i];
            auto it = prev(st.end());

            if(*it >= required){
                st.erase(it);
            }
            else if(pillUsed >= pills){
                return false;
            }
            else{
                auto weakestWorker = st.lower_bound(required - strength);
                if(weakestWorker == st.end()) return false;

                st.erase(weakestWorker);
                pillUsed++; 
            }
        }

        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size();
        int n = workers.size();

        int s = 0;
        int e = min(m,n);

        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers), greater<int>());

        int result = 0;
        while(s <= e){
            int mid = s+(e-s)/2;

            if(check(tasks, workers, pills, strength, mid)){
                result = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return result;
    }
};