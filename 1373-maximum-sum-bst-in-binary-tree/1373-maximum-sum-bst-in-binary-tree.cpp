class Solution {
public:
    int ans = 0;

    vector<int> solve(TreeNode* root) {
        if (!root) 
            return {1, 0, INT_MAX, INT_MIN}; 
        // {isBST, sum, min, max}

        auto left = solve(root->left);
        auto right = solve(root->right);

        // Check BST condition
        if (left[0] && right[0] && 
            root->val > left[3] && 
            root->val < right[2]) {

            int sum = left[1] + right[1] + root->val;
            ans = max(ans, sum);

            return {1, sum,
                    min(root->val, left[2]),
                    max(root->val, right[3])};
        }

        return {0, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};
