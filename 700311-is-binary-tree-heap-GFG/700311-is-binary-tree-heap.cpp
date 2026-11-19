/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isHeap(Node* root) {
        // code here
        queue<Node*> q;
        if(root) q.push(root);
        bool null_enc = false;
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            bool left_exist = false;
            
            if(null_enc && temp->left) return false;
            
            if(temp->left){
                left_exist = true;
                if(temp->data < temp->left->data) return false;
                q.push(temp->left);
            }
            else null_enc = true;
            
            if(null_enc && temp->right) return false;
            if(!left_exist && temp->right) return false;
            
            if(temp->right){
                if(temp->data < temp->right->data) return false;
                q.push(temp->right);
            }
            else null_enc = true;
        }
        
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna