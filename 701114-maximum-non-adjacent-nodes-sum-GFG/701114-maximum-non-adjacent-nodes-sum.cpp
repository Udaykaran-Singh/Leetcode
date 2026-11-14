/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
    
    pair<int, int> solve(Node *root){
        if(!root) return make_pair(0, 0);
        
        // takingCurr, leavingCurr
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        int takingCurr = root->data + left.second + right.second;
        int leavingCurr = max({left.first + right.first, left.first + right.second, left.second + right.first, left.second + right.second});
        
        return make_pair(takingCurr, leavingCurr);
    }
    
  public:
    int getMaxSum(Node *root) {
        // code here
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna