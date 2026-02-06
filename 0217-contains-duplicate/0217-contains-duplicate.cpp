class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        for (auto &p : mp) {
            // p.first  → number
            // p.second → frequency
            if (p.second > 1) {
                return true;
            }
        }
        return false;
    }
};
