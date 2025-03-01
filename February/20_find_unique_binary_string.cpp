// 1980. Find Unique Binary String

// Method1: 
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for(string &num : nums){
            st.insert(stoi(num, 0, 2));
        }

        for(int i=0; i<=n; i++){
            if(!st.count(i)){
                // convert into 16 bit and then trim int nums[i].size
                string num = bitset<16>(i).to_string();
                return num.substr(16-n, n);
            }
        }

        return "";
    }
};


// Method2:
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result = "";

        for(int i=0; i<n; i++){
            char ch = nums[i][i];
            result += (ch=='0' ? '1' : '0');
        }

        return result;
    }
};