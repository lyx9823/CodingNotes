// my solution
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> char_count;
        for(int i=0; i<magazine.length(); i++) {
            char_count[magazine[i]]++;
        }

        for(int i=0; i<ransomNote.length(); i++) {
            char_count[ransomNote[i]]--;
            if(char_count[ransomNote[i]]<0) {
                return false;
            }
        }
        return true;
    }
};

// offitial solution: https://leetcode.cn/problems/ransom-note/solutions/1135839/shu-jin-xin-by-leetcode-solution-ji8a/
// 字符相关的都可以转为数字
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        vector<int> cnt(26);
        for (auto & c : magazine) {
            cnt[c - 'a']++;
        }
        for (auto & c : ransomNote) {
            cnt[c - 'a']--;
            if (cnt[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
