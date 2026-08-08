class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;

     
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxi = sum;

     
        for (int right = k; right < nums.size(); right++) {
            sum += nums[right];       
            sum -= nums[right - k];   

            maxi = max(maxi, sum);
        }

        return (double)maxi / k;
    }
};