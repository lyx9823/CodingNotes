// https://leetcode.cn/problems/3sum/solutions/11525/3sumpai-xu-shuang-zhi-zhen-yi-dong-by-jyd
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            if((i>0) && (nums[i]==nums[i-1])) {
                continue;
            }
            
            int j = i+1, k = n-1;
            while(j<k) {
                // 如果此处先去重, 会漏掉(0, 0, 0)这种组合

                // 先判断和是否=0
                if((nums[i]+nums[j]+nums[k]) > 0) {
                    k--;
                }else if((nums[i]+nums[j]+nums[k]) < 0) {
                    j++;
                }else {
                    res.push_back({nums[i], nums[j], nums[k]});

                    // 找到一个三元组后, 对j k去重
                    while((j<k) && (nums[j]==nums[j+1])) {
                        j++;
                    }
                    while((j<k) && (nums[k]==nums[k-1])) {
                        k--;
                    }
                    j++;
                    k--;
                }
            }
        }

        return res;
    }
};
