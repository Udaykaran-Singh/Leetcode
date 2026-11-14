/* Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    
    bool solve(Node *root, int& k, int node, int& ans){
        if(!root) return false;
        
        if(root->data == node) return true;
        
        bool left = solve(root->left, k, node, ans);
        bool right = solve(root->right, k, node, ans);
        
        if(left || right){
            k--;
            if(!k) ans = root->data;
            return true;
        }
        
        return false;
    }
    
  public:
    int kthAncestor(Node *root, int k, int node) {
        // code here
        int ans = -1;
        solve(root, k, node, ans);
        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna