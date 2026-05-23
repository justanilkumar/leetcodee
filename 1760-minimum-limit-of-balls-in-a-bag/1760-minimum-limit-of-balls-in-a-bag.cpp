class Solution {
public:

    bool possible(vector<int>& nums, int maxOperations, int mid) {

        long long operations = 0;

        for(int x : nums) {

            operations += x / mid;

            // if perfectly divisible
            if(x % mid == 0)
                operations--;

            if(operations > maxOperations)
                return false;
        }

        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        int ans = high;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(possible(nums, maxOperations, mid)) {

                ans = mid;
                high = mid - 1;
            }
            else {

                low = mid + 1;
            }
        }

        return ans;
    }
};