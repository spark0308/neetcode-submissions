class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push('-');
        for(char x : s){
            char top = st.top();
            if(x == ')' && top == '(') st.pop();
            else if(x == '}' && top == '{') st.pop();
            else if(x == ']' && top == '[') st.pop();
            else st.push(x);
        }
        char top = st.top();
        if(top == '-') return true;
        return false;
    }
};
