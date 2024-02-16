// my solution
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

// offitial solution: https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/solutions/643955/shan-chu-zi-fu-chuan-zhong-de-suo-you-xi-4ohr/
// 在C++中，由于 std::string\texttt{std::string}std::string 类本身就提供了类似「入栈」和「出栈」的接口，因此我们直接将需要被返回的字符串作为栈即可。
class Solution {
public:
    string removeDuplicates(string s) {
        string stk;
        for (char ch : s) {
            if (!stk.empty() && stk.back() == ch) {
                stk.pop_back();
            } else {
                stk.push_back(ch);
            }
        }
        return stk;
    }
};

