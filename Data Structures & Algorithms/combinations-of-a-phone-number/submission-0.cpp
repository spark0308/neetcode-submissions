class Solution {
    map<char, vector<char>> keypad;

    vector<string> ans;
    void combinate(string& digits, int idx, int n, string& word){
        if(idx == n){
            if(word != "") ans.push_back(word);
            return;
        }

        for(auto x : keypad[digits[idx]]){
            word = word + x;
            combinate(digits, idx + 1, n, word);
            word = word.substr(0, word.length()-1);
        }
    }
public:
    Solution(){
        keypad['2'] = {'a', 'b', 'c'};
        keypad['3'] = {'d', 'e', 'f'};
        keypad['4'] = {'g', 'h', 'i'};
        keypad['5'] = {'j', 'k', 'l'};
        keypad['6'] = {'m', 'n', 'o'};
        keypad['7'] = {'p', 'q', 'r', 's'};
        keypad['8'] = {'t', 'u', 'v'};
        keypad['9'] = {'w', 'x', 'y', 'z'};
    }

    vector<string> letterCombinations(string digits) {
        string word = "";
        combinate(digits, 0, digits.length(), word);

        return ans;
    }
};
