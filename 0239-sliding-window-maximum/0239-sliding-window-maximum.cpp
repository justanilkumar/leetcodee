class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;        // stores indices
        vector<int> result;

        for(int i = 0; i < nums.size(); i++) {

            // 1. Remove indices out of window
            if(!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // 2. Remove smaller elements from back
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // 3. Add current index
            dq.push_back(i);

            // 4. Store result when window size = k
            if(i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};