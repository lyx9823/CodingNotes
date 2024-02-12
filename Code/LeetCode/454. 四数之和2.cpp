// 四数问题->两数问题
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> nums_count; 
        int n = nums1.size();
        int res = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                nums_count[(nums1[i]+nums2[j])]++;
            }
            
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(nums_count.find(0-(nums3[i]+nums4[j]))!=0) {
                    res += nums_count[-(nums3[i]+nums4[j])];
                }
            }
        }
        
        return res;
    }
};
