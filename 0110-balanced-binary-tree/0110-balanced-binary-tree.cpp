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
    pair<int, bool> solve(TreeNode* root){
        if(root == NULL) return make_pair(0, true);

        pair<int, bool> left = solve(root->left);
        pair<int, bool> right = solve(root->right);

        if(!left.second || !right.second) return make_pair(0, false);

        if(abs(right.first - left.first) <= 1){
            return make_pair(max(right.first, left.first) + 1, true);
        }

        return make_pair(0, false);

    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(root->right == NULL && root->left == NULL) return true;

        return solve(root).second;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna