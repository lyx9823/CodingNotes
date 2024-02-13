class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int left = s.length()-1, right = s.length()-1;
        while(left>=0) {
            // 跳过字符串尾部空格
            while((left>=0) && (s[left] == ' ')) {
                left--;
            }
            // 找到单词尾
            right = left;
            
            // 找到单词头
            while((left>=0) && (s[left]!=' ')) {
                left--;
            }

            // 跳过字符串头部空格
            if(right>=0) {
                res.append(s.substr(left+1, right-left)+" ");
                right = left;
            }   
        }

        // 去除最后一个空格
        return res.substr(0, res.length()-1);
    }
};
