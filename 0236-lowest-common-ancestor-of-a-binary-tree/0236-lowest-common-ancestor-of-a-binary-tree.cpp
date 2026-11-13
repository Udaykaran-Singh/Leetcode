/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    TreeNode* ans = NULL;

    bool solve(TreeNode* root, TreeNode* &p, TreeNode* &q){
        if(!root) return false;

        if(root == p || root == q){
            ans = root;
            return true;
        }

        bool left = solve(root->left, p, q);
        bool right = solve(root->right, p, q);

        if(left && right) ans = root;

        return left || right;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p, q);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna