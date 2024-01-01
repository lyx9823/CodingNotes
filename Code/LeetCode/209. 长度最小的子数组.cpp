// my solution1: 会超时
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = 0, sum = 0, min_res = nums.size()+1;
        int left = 0, right = 0;
        while((left < nums.size()) && (right < nums.size())) {
            sum += nums[right];
            res ++;
            if(res >= min_res) {
                left++;
                right = left;
                res = 0;
                sum = 0;
                continue;
            }
            if(sum >= target) {
                if(res < min_res) {
                    min_res = res;
                } 
                left++;
                right = left;
                res = 0;
                sum = 0;
            } else {
                right++;
            }
        }

        if(min_res != (nums.size()+1)) {
            return min_res;
        } else {
            return 0;
        }
    }
};

// my solution2: 滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = 0, sum = 0, min_res = nums.size()+1;
        int left = 0, right = 0;
        while((left < nums.size()) && (right < nums.size())) {
            sum += nums[right];
            res ++;
            while(sum >= target) {
                if(res < min_res) {
                    min_res = res;
                }
                sum -= nums[left];
                left++;
                res--;      // res = right - left + 1; 可以通过left & right来维护
            }
            right++;
        }

        if(min_res != (nums.size()+1)) {
            return min_res;
        } else {
            return 0;
        }
    }
};

// offitial solution: https://leetcode.cn/problems/minimum-size-subarray-sum/solutions/305704/chang-du-zui-xiao-de-zi-shu-zu-by-leetcode-solutio/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;
        while (end < n) {
            sum += nums[end];
            while (sum >= s) {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
