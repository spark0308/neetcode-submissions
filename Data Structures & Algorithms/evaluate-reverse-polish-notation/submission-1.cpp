class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(auto x : tokens){
            if(x == "+"){
                int operand2 = s.top();
                s.pop();
                int operand1 = s.top();
                s.pop();
                s.push(operand1 + operand2);
            }
            else if(x == "-"){
                int operand2 = s.top();
                s.pop();
                int operand1 = s.top();
                s.pop();
                s.push(operand1 - operand2);
            }
            else if(x == "*"){
                int operand2 = s.top();
                s.pop();
                int operand1 = s.top();
                s.pop();
                s.push(operand1 * operand2);
            }
            else if(x == "/"){
                int operand2 = s.top();
                s.pop();
                int operand1 = s.top();
                s.pop();
                s.push(operand1/operand2);
            }
            else{
                s.push(stoi(x));
            }
        }

        if(s.empty()) return 0;
        return s.top();
    }
};
