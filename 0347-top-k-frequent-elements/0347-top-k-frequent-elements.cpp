class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        // Step 1: Count frequency
        for(int num : nums) {
            freq[num]++;
        }

        // Step 2: Store in vector
        vector<pair<int,int>> arr;
        for(auto it : freq) {
            arr.push_back({it.first, it.second});
        }

        // Step 3: Sort by frequency (descending)
        sort(arr.begin(), arr.end(), [](pair<int,int>& a, pair<int,int>& b){
            return a.second > b.second;
        });

        // Step 4: Take first k elements
        vector<int> result;
        for(int i = 0; i < k; i++) {
            result.push_back(arr[i].first);
        }

        return result;
    }
};