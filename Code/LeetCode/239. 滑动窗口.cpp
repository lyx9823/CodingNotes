// 暴力版
class Solution {
public:
    int find_max(vector<int>& input, int k) {
        int res = -100000;
        for (int i = 0; i < k; i++) {
            if (input[i] > res) {
                res = input[i];
            }
        }
        return res;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int i = 0, temp_max = 0;
        vector<int> temp(k, 0);
        while ((i == 0) || ((i+k) <= (nums.size()))) {
            for (int j = 0; j < k; j++)
            {
                temp[j] = nums[i + j];	// i+j<nums.size()
            }
            temp_max = find_max(temp, k);
            res.push_back(temp_max);
            i++;
        }
        return res;
    }
};

// 单调栈
class Solution {
public:
    // 单调栈
    class MonoQueue {
    public:
        deque<int> que;

        // 每次pop时和que队头对比
        void pop(int value) {
            if (!que.empty() && (value == que.front())) {
                que.pop_front();
            }
        }

        // 每次push和que尾部的元素对比
        void push(int value) {
            while (!que.empty() && (value > que.back())) {
                que.pop_back();
            }
            que.push_back(value);
        }

        int front() {
            return que.front();
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonoQueue que;
        vector<int> res;

        int i = 0;
        for (i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        res.push_back(que.front());

        while (i < nums.size()) {
            que.pop(nums[i-k]);
            que.push(nums[i]);
            res.push_back(que.front());
            i++;
        }

        return res;
    }
};
