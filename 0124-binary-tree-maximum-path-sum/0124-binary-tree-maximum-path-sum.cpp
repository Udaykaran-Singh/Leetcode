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

    int maxNodeVal;

    pair<int, int> solve(TreeNode* root){
        if(!root) return make_pair(0, 0);

        // max_sum(like diameter), curr >= 0(like one bloodline)
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        maxNodeVal = max(maxNodeVal, root->val);

        int maxCurrSum = max(left.second + root->val,  right.second + root->val);
        if(maxCurrSum < 0) maxCurrSum = 0;

        int maxOfAll = max(max(left.first, right.first), max(maxCurrSum, left.second + right.second + root->val));


        return make_pair(maxOfAll, maxCurrSum);

    }

public:
    int maxPathSum(TreeNode* root) {
        maxNodeVal = INT_MIN;
        pair<int, int> ans = solve(root);

        if(maxNodeVal <= 0) return maxNodeVal;

        return ans.first;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna