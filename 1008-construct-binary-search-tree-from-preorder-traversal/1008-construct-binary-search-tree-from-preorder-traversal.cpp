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

    TreeNode* solve(vector<int>& preorder, int& i, int n, int low, int high){
        if(i >= n) return NULL;

        if(!(low < preorder[i] && preorder[i] < high)) return NULL;

        TreeNode* temp = new TreeNode(preorder[i++]);

        temp->left = solve(preorder, i, n, low, temp->val);
        temp->right = solve(preorder, i, n, temp->val, high);

        return temp;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return solve(preorder, i, preorder.size(), INT_MIN, INT_MAX);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna