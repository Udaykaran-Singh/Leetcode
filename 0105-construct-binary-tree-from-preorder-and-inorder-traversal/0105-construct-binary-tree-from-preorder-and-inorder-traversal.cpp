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

    unordered_map<int, int> mp;

    TreeNode* solve(vector<int>& preorder, int i, int j, int& k) {
        if (i > j) return NULL;

        TreeNode* temp = new TreeNode(preorder[k]);

        int u = mp[preorder[k]];
        k++;

        temp->left = solve(preorder, i, u - 1, k);
        temp->right = solve(preorder, u + 1, j, k);

        return temp;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        if (n == 0) return NULL;

        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        int k = 0;

        return solve(preorder, 0, n - 1, k);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna