class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;  // prefix sum divisible by k
        
        int sum = 0, ans = 0;
        
        for (int x : nums) {
            sum += x;
            int rem = (sum % k + k) % k; // handle negative
            
            ans += mp[rem];
            mp[rem]++;
        }
        
        return ans;
    }
};
