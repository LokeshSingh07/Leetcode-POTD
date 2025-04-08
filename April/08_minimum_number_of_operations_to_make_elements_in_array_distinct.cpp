// 3396. Minimum Number of Operations to Make Elements in Array Distinct

// Method 1: Brute force 
class Solution {
public:
    bool check(vector<int> &nums, int i, int j){
        unordered_map<int, int> mp;

        for(int k=i; k<=j; k++){
            mp[nums[k]]++;
            if(mp[nums[k]] > 1) return false;
        }

        return true;
    }

    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=n-1;
        int maxOpn = (n+3-1)/3;
        int opn = 0;

        while(opn != maxOpn){
            if(check(nums, i, j) == true){
                return opn;
            }
            opn++;
            i += 3;
        }
        
        return maxOpn;
    }
};


// Method 2: optimised
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int maxOpn = (n+2)/3;
        int j=n-1;

        while(maxOpn-- && j>=0){
            int k;
            if(n % 3 == 0) k=3;
            else{
                k = n % 3;
                n = 3;
            }
            
            while(k-- && j>=0){
                if(st.count(nums[j])) return maxOpn+1;
                st.insert(nums[j]);
                j--;
            } 
        }

        return 0;
    }
};


// Method 2: clean code
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int j=n-1;

        while(j >= 0){         
            if(st.count(nums[j])) return j/3+1;
            st.insert(nums[j]);
            j--;
        } 

        return 0;
    }
};