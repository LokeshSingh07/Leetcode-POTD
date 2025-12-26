// 3606. Coupon Code Validator

class Solution {
public:
    bool isValid(string &code){
        if(code.empty()) return false;
        for(auto &c: code){
            if(!(isalpha(c) || isdigit(c) || c == '_')) return false;
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> validBusiness = {"restaurant","grocery","pharmacy","electronics"};
        vector<pair<string,string>> temp;

        for(int i=0; i<code.size(); i++){
            if(isValid(code[i]) &&
                isActive[i] && 
                find(begin(validBusiness), end(validBusiness), businessLine[i]) != end(validBusiness) 
            ){
                temp.push_back({businessLine[i], code[i]});
            }
        }

        sort(begin(temp), end(temp));

        vector<string> result;
        for(auto &it: temp){
            result.push_back(it.second);
        }

        return result;
    }
};