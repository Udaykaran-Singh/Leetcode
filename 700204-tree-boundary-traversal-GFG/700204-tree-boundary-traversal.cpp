/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
    
    void solve_left(Node *root, vector<int>& ans){
        if(!root) return;
        if(!root->left && !root->right) return;
        
        ans.push_back(root->data);
        
        if(root->left) solve_left(root->left, ans);
        else solve_left(root->right, ans);
        
    }
    
    void solve(Node *root, vector<int>& ans){
        if(!root) return;

        if(!root->left && !root->right){
            ans.push_back(root->data);
            return;
        }
        
        solve(root->left, ans);
        solve(root->right, ans);
    }
    
    void solve_right(Node *root, vector<int>& ans){
        if(!root) return;
        if(!root->left && !root->right) return;
        
        
        if(root->right) solve_right(root->right, ans);
        else solve_right(root->left, ans);
        
        ans.push_back(root->data);
        
       
    }
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
    
        ans.push_back(root->data);
        
        
        solve_left(root->left, ans);
        
        solve(root->left, ans);
        solve(root->right, ans);
        
        solve_right(root->right, ans);
        
        
        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna