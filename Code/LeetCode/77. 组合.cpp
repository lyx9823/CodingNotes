// points: 组合是无序的, <1, 4>和<4, 1>被认为是一样的; 全排列是有序的<1, 4>和<4, 1>是不一样的

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void combineBacktrace(int n, int k, int startIndex) {
        if(path.size() == k) {
            res.push_back(path);
            return;
        }

        for(int i=startIndex; i<=n; i++) {
            path.push_back(i);
            combineBacktrace(n, k, i+1);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        combineBacktrace(n, k, 1);

        return res;
    }
};
