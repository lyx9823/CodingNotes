// my solution
class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        
        for(int i=0; i<s.length(); i++) {
            char temp = s[i];
            if(((temp == ')') || (temp == '}') || (temp == ']')) && res.empty()) {
                return false;
            }else if((temp == ')') && (res.top() == '(')) {
                res.pop();
            }else if((temp == '}') && (res.top() == '{')) {
                res.pop();
            }else if((temp == ']') && (res.top() == '[')) {
                res.pop();
            }else if((temp == '(') || (temp == '{') || (temp == '[')) {
                res.push(temp);
            }else {
                return false;
            }
        }
        
        return res.empty();
    }
};

// offitial solution
// 在匹配左括号的时候，右括号先入栈，就只需要比较当前元素和栈顶相不相等就可以了，比左括号先入栈代码实现要简单的多了！
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false; // 如果s的长度为奇数，一定不符合要求
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            // 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
            // 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop(); // st.top() 与 s[i]相等，栈弹出元素
        }
        // 第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
        return st.empty();
    }
};
