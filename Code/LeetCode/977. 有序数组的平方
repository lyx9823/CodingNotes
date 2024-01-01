// my solution
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sorted_nums(nums.size());
        int i = nums.size()-1;
        int left = 0;
        int right = nums.size()-1;
        while(left <= right) {
            if((nums[left] * nums[left]) <= (nums[right] * nums[right])) {
                sorted_nums[i] = nums[right] * nums[right];
                right--;
                i--;      // i--; 可以提出来
            } else {
            sorted_nums[i] = nums[left] * nums[left];
            left++;
            i--;
            }
        }
        return sorted_nums;
    }
};

// offitial solution: https://leetcode.cn/problems/squares-of-a-sorted-array/solutions/447736/you-xu-shu-zu-de-ping-fang-by-leetcode-solution/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i];
                ++i;
            }
            else {
                ans[pos] = nums[j] * nums[j];
                --j;
            }
            --pos;
        }
        return ans;
    }
};
