class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int i = 0;

        // 1️⃣ increasing
        for (; i + 1 < n; i++) {
            if (nums[i] < nums[i + 1])
                continue;
            break;
        }
        if (i == 0 || i == n - 1) return false;

        // 2️⃣ decreasing
        int mid = i;
        for (; i + 1 < n; i++) {
            if (nums[i] > nums[i + 1])
                continue;
            break;
        }
        if (i == mid || i == n - 1) return false;

        // 3️⃣ increasing
        for (; i + 1 < n; i++) {
            if (nums[i] < nums[i + 1])
                continue;
            break;
        }

        return i == n - 1;
    }
};
