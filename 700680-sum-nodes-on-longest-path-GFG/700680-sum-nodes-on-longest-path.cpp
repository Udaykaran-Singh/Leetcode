/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
    
    pair<int, int> solve(Node* root){
        if(!root) return make_pair(0, 0);
        
        // sum, height  
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        if(left.second > right.second)
            return make_pair(left.first + root->data, left.second + 1);
        else if(right.second > left.second)
            return make_pair(right.first + root->data, right.second + 1);
        
        
        return make_pair(max(left.first, right.first) + root->data, right.second + 1);
    }
    
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        return solve(root).first;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna