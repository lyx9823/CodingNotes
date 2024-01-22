class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        std::unordered_map<char, int> char_map(0);
        for(int i=0; i<s.length(); i++) {
            char_map[s[i]]++;
            char_map[t[i]]--;
        }
        for(auto iter = char_map.begin(); iter!=char_map.end(); iter++) {
            if((iter->second) != 0) {
                return false;
            }
        }
        return true;
    }
};
