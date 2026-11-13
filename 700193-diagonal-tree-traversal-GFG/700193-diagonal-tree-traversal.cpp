/* Structure of binary tree node
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
    
    void solve(Node *root, map<int, vector<int>>& map, int level){
        if(!root) return;
        
        map[level].push_back(root->data);
        
        solve(root->left, map, level + 1);
        solve(root->right, map, level);
        
    }
    
  public:
    vector<int> diagonal(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        
        map<int, vector<int>> map;
        
        solve(root, map, 0);
        
        for(auto i : map){
            for(auto j : i.second){
                ans.push_back(j);
            }
        }
        
        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna