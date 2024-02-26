class Solution {
public:
    class topkcmp {
    public:
        bool operator()(const pair<int, int>& left, const pair<int, int>& right) {
            return left.second > right.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nums_map;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            nums_map[nums[i]]++;
        }
        
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, topkcmp> topk_queue;
        for (auto iter = nums_map.begin(); iter != nums_map.end(); iter++) {
            topk_queue.push(*iter);
            if (topk_queue.size() > k) {
                topk_queue.pop();
            }
        }

        while (topk_queue.size() > 0) {
            cout << topk_queue.top().first << endl;
            res.push_back(topk_queue.top().first);
            topk_queue.pop();
        }
        
        return res;
    }
};
