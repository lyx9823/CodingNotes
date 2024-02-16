class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> res;

        for(int i=0; i<s.length(); i++) {
            char temp = s[i];
            if((!res.empty()) && (res.top()==temp)) {
                res.pop();
            } else {
                res.push(temp);
            }
        }

        string ss = "";
        while(!res.empty()) {
            ss = res.top() + ss;
            res.pop();
        }

        return ss;
    }
};
