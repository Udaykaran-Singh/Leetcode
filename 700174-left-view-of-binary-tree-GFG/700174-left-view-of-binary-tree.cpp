/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
    
    void solve(Node *root, vector<int>& ans, int level){
        if(!root) return;
        
        if(ans.size() == level) ans.push_back(root->data);
        
        solve(root->left, ans, level + 1);
        solve(root->right, ans, level + 1);
    }
    
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        solve(root, ans, 0);
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna