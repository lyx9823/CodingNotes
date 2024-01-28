class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums_count(1000, 0);
        unordered_set<int> nums_res;

        for(int i=0; i<nums1.size(); i++) {
            nums_count[nums1[i]]++;
        }

         for(int i=0; i<nums2.size(); i++) {
            if(nums_count[nums2[i]] > 0) {
                nums_res.insert(nums2[i]);   
            }
        }

        return vector<int>(nums_res.begin(), nums_res.end());  //直接用map的迭代器初始化vector
    }
};
