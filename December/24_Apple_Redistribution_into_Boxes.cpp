// 3074. Apple Redistribution into Boxes

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(begin(apple), end(apple),0);
        sort(begin(capacity), end(capacity), greater<int>());

        int rem=0;
        while(sum > 0){
            sum -= capacity[rem];
            rem++;
        }

        return rem;
    }
};