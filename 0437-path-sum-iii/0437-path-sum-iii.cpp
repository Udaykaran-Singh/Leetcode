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

    void solve(TreeNode* root, int& targetSum, vector<int>& store, int& count){
        if (!root) return;

        store.push_back(root->val);

        long long sum = 0;

        for (int i = store.size() - 1; i >= 0; i--) {
            sum += store[i];
            if (sum == targetSum) count++;
        }

        solve(root->left, targetSum, store, count);
        solve(root->right, targetSum, store, count);

        store.pop_back();
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> store;
        int count = 0;
        solve(root, targetSum, store, count);

        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna