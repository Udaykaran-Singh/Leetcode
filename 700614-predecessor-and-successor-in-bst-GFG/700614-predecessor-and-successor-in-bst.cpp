/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
    
    void solve(Node* root, int key, vector<Node*>& ans){
        if(!root) return;
        
        solve(root->left, key, ans);
        
        if(root->data < key) ans[0] = root;
        else if(root->data > key && !ans[1]) ans[1] = root;
        
        if(ans[1]) return;
        
        solve(root->right, key, ans);
        
    }
    
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans(2, NULL);
        solve(root, key, ans);
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna