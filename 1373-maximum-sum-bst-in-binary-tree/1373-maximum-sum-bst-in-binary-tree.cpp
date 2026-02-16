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
    int maxSum = 0;
    
    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };
    
    Info solve(TreeNode* root) {
        if (!root) 
            return {true, 0, INT_MAX, INT_MIN};
        
        Info left = solve(root->left);
        Info right = solve(root->right);
        
        // Check BST condition
        if (left.isBST && right.isBST && 
            root->val > left.maxVal && 
            root->val < right.minVal) {
            
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currSum);
            
            return {
                true,
                currSum,
                min(root->val, left.minVal),
                max(root->val, right.maxVal)
            };
        }
        
        return {false, 0, 0, 0};
    }
    
    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};
