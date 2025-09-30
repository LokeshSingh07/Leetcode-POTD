// 966. Vowel Spellchecker

class Solution {
public:
    unordered_set<string> exactWords;
    unordered_map<string,string> caseMap;
    unordered_map<string,string> vowelMap;

    string toLower(string &s){
        string result = s;
        for(auto &ch: result){
            ch = tolower(ch);
        }
        return result;
    }

    string maskVowels(string &s){
        string result = s;
        for(auto &ch: result){
            if(string("aeiou").find(ch) != string::npos){
                ch = '*';
            }
        }
        return result;
    }

    string findMatch(string &s){
        if(exactWords.find(s) != exactWords.end()){
            return s;
        }

        string lowerWord = toLower(s);
        if(caseMap.find(lowerWord) != caseMap.end()){
            return caseMap[lowerWord];
        }


        string maskWord = maskVowels(lowerWord);
        if(vowelMap.find(maskWord) != vowelMap.end()){
            return vowelMap[maskWord];
        }

        return "";    
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exactWords.clear();
        caseMap.clear();
        vowelMap.clear();

        for(auto word: wordlist){
            exactWords.insert(word);

            string lowerWord = toLower(word);
            if(caseMap.find(lowerWord) == caseMap.end()){
                caseMap[lowerWord] = word;
            }

            string maskWord = maskVowels(lowerWord);
            if(vowelMap.find(maskWord) == vowelMap.end()){
                vowelMap[maskWord] = word;
            }
        }

        vector<string> result;
        for(auto query: queries){
            result.push_back(findMatch(query));
        }

        return result;
    }
};