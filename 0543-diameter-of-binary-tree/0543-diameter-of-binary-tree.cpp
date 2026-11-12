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
class store{
    int height;
    int diameter;

    friend class Solution;
};

class Solution {
    store solve(TreeNode* root){
        if(!root){
            store a;
            a.height = 0;
            a.diameter = 0;
            return a;
        }

        store temp1 = solve(root->left);
        store temp2 = solve(root->right);

        store ans;
        ans.height = 1 + max(temp1.height, temp2.height);
        ans.diameter = max((temp1.height + 1 + temp2.height), max(temp1.diameter, temp2.diameter));

        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).diameter - 1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna