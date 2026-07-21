class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> pos;

      
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x)
                pos.push_back(i);
        }

        vector<int> ans;

        // Answer each query
        for (int q : queries) {
            if (q <= pos.size())
                ans.push_back(pos[q - 1]);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};