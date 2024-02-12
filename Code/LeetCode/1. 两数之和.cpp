// my solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int len = sorted_nums.size();
        int left = 0, right = len-1;
        vector<int> res;
        int res0, res1;
        while(left != right) {
            int sum = sorted_nums[left] + sorted_nums[right];
            if(sum == target) {
                res0 = sorted_nums[left];
                res1 = sorted_nums[right];
                break;
            } else if(sum > target) {
                right--;
            } else {
                left++;
            }
        }
        for(int i=0, index=2; i<nums.size(), index>0; i++) {
            if((res0==nums[i]) || (res1==nums[i])) {
                res.push_back(i);
                index--;
            }
        }
        return res;
    }
};


// offitial solution: https://leetcode.cn/problems/two-sum/solutions/434597/liang-shu-zhi-he-by-leetcode-solution/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

