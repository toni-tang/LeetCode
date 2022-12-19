class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stk;
        
        for(int i = 0; i < tokens.size(); i++)
        {
            long long x, y;
            
            if(tokens[i] == "+")
            {
                x = stk.top(); stk.pop();
                y = stk.top(); stk.pop();
                stk.push(y+x);
            }
            else if(tokens[i] == "-")
            {
                x = stk.top(); stk.pop();
                y = stk.top(); stk.pop();
                stk.push(y-x);
            }
            else if(tokens[i] == "/")
            {
                x = stk.top(); stk.pop();
                y = stk.top(); stk.pop();
                stk.push(y/x);
            }
            else if(tokens[i] == "*")
            {
                x = stk.top(); stk.pop();
                y = stk.top(); stk.pop();
                stk.push(y*x);
            }
            else
            {
                stk.push(stoi(tokens[i]));
            }
        }
        
        return (int)stk.top();
    }
};