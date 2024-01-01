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
