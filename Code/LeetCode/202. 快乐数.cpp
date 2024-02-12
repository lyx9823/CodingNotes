class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> num_map;
        int res = 0;
        while(res != 1) {
            res = 0;
            while(n!=0) {
                res += (n%10)*(n%10);
                n = n/10;
            }
            if(num_map.find(res)!=num_map.end()) {
                return false;
            }
            num_map.insert(res);
            n = res;
        }
        return true;
    }
};
