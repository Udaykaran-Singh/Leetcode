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
    bool flag;
    int total;

    void solve(TreeNode* root){
        if(!root) return;

        solve(root->left);

        if(flag){
            int data = root->val;
            root->val = total;
            total -= data;
        }
        else{
            total += root->val;
        }

        solve(root->right);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        total = 0;
        flag = false;
        solve(root);

        flag = true;
        solve(root);

        return root;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna