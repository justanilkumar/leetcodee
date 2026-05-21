class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
    
int pre =1;
int stuff=1;

        for(int i=0;i<n;i++) {
            if(pre==0) pre =1;
            if(stuff==0) stuff =1;

            pre *=nums[i];
            stuff*=nums[n-i-1];
            ans=max(ans,max(pre,stuff));
        }
        return ans;
    }
};