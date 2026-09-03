class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;

        // Prefix sum 0 has occurred once
        mp[0] = 1;

        int prefix = 0;
        int ans = 0;

        for (int x : nums) {
            prefix += x;

            // Need an earlier prefix of prefix - goal
            if (mp.find(prefix - goal) != mp.end()) {
                ans += mp[prefix - goal];
            }

            // Store current prefix sum
            mp[prefix]++;
        }

        return ans;
    }
};