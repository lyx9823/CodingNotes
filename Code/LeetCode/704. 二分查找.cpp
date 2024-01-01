// my solution
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();
        int mid = (start + end)/2;

        for(int i=0; i<(nums.size()/2)+1; i++) {
            if(target == nums[mid]) {
                return mid;
            } else if(target < nums[mid]) {
                start = 0;
                end = mid;
            } else {
                start = mid;
            }
            mid = (start + end)/2;
        }
        return -1;
    }
};

// offitial solution: https://leetcode.cn/problems/binary-search/solutions/980494/er-fen-cha-zhao-by-leetcode-solution-f0xw/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (right - left) / 2 + left;
            int num = nums[mid];
            if (num == target) {
                return mid;
            } else if (num > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
