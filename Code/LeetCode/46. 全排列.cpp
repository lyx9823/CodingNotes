// points: 组合是无序的, <1, 4>和<4, 1>被认为是一样的; 全排列是有序的<1, 4>和<4, 1>是不一样的

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void numsTracing(vector<int>& nums, vector<bool>& used) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            if(used[i] == true)
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            numsTracing(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        numsTracing(nums, used);

        return res;
    }
};
