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

    TreeNode* solve(vector<int>& postorder, int i, int j, int& k) {
        if (i > j) return NULL;

        TreeNode* temp = new TreeNode(postorder[k]);

        int u = mp[postorder[k]];
        k--;

        temp->right = solve(postorder, u + 1, j, k);
        temp->left = solve(postorder, i, u - 1, k);

        return temp;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if (n == 0) return NULL;

        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        int k = n - 1;

        return solve(postorder, 0, n - 1, k);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna