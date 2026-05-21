class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> preSumMap; 
        preSumMap[0] = 1;   // Important!
        
        int count = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int rem = sum - k;
            if (preSumMap.find(rem) != preSumMap.end()) {
                count += preSumMap[rem];
            }

            preSumMap[sum]++;
        }

        return count;
    }
};
