class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> cal;
        long long left = 0, right = 0;
        for (int i = 0; i < tokens.size(); i++) {
            string s = tokens[i];
            if ((s == "+") || (s == "-") || (s == "*") || (s == "/")) {
                right = cal.top();
                cal.pop();
                left = cal.top();
                cal.pop();
                if (s == "+") {
                    cal.push(left + right);
                }else if (s == "-") {
                    cal.push(left - right);
                }else if (s == "*") {
                    cal.push(left * right);
                }else if (s == "/") {
                    cal.push(left / right);
                }
            } else {
                cal.push(stoll(s));
            }
        }
        return int(cal.top());
    }
};
