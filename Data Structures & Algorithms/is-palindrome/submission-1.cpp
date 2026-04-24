class Solution {
public:
    string removeSpace(string s){
        for(int i=0; i<s.length(); i++){
            bool isUpperCase = (s[i] >= 65 && s[i] <= 90);
            bool isLowerCase = (s[i] >= 97 && s[i] <= 122);
            bool isNumber = (s[i] >= 48 && s[i] <= 57);
            if (!isUpperCase && !isLowerCase && !isNumber)
            {
                s.erase(s.begin() + i);
                i--;
            }
            else{
                if(isUpperCase) s[i] = s[i] + 32;
            }
        }
        return s;
    }
    bool isPalindrome(string s) {
        s = removeSpace(s);
        cout<<s<<endl;
        int i = 0;
        int j = s.length() - 1;

        for(; i<=j; i++, j--){
            if(s[i] != s[j]) return false;
        }

        return true;
    }
};
