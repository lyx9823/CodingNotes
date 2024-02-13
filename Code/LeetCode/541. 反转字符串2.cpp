class Solution {
public:
    void reverseString(string& s, int left, int right) {
        char temp;
        while(left < right) {
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }

    string reverseStr(string s, int k) {
        int len = s.length();
        for(int i=0; i<len; i=i+k*2) {
            if(i+k >= len) {
                reverseString(s, i, len-1);
            } else {
                reverseString(s, i, i+k-1);
            }
        }
        return s;
    }
};
