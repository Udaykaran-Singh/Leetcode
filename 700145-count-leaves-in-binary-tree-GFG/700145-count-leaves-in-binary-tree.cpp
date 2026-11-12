/* Binary Tree node Structure 
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
    int ans = 0;
    
    void solve(Node* root){
        // base case
        if(!root) return;
        
        if(!root->right && !root->left){
            ans++;
            return;
        }
        
        solve(root->left);
        solve(root->right);
    }
    
  public:
    int countLeaves(Node* root) {
        // code here
        ans = 0;
        solve(root);
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna