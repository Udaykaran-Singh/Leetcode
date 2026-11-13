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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bool leftToRight = true;
        queue<TreeNode*> q;

        if(root) q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> store(size);

            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();

                int index = leftToRight ? i : size - i - 1;
                store[index] = temp->val;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            leftToRight = !leftToRight;
            ans.push_back(store);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna