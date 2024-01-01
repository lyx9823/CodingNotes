// my solution
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = nums.size()-1;
        int i = 0;
        while(i <= res)
        {
            if(nums[i] == val) {
                if(nums[res] != val){  // 这一步其实不用判断, 不管num[res]是否=val, 直接拷贝到num[i], 因为下一步还是会判断nums[i]
                    nums[i] = nums[res];
                    nums[res] = val;
                } else {
                    res--;
                }
            } else {
                i++;
            }
        }
        return (res + 1);
    }
};

// offitial solution
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = nums.size()-1;
        int i = 0;
        while(i <= res)
        {
            if(nums[i] == val) {
                nums[i] = nums[res];
                res--;
            } else {
                i++;
            }
        }
        return (res + 1); // return i;
    }
};
