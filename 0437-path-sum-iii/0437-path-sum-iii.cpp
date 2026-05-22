/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int dfs(TreeNode* root, long long currSum, int target,
            unordered_map<long long, int>& mpp) {
        
        if(root == NULL) return 0;

        currSum += root->val;

        int count = mpp[currSum - target];

        mpp[currSum]++;

        count += dfs(root->left, currSum, target, mpp);
        count += dfs(root->right, currSum, target, mpp);

        mpp[currSum]--;

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        
        unordered_map<long long, int> mpp;

        mpp[0] = 1;

        return dfs(root, 0, targetSum, mpp);
    }
};