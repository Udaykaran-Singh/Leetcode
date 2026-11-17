/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    Node *flattenBST(Node *curr) {
        // code here
        Node *head = NULL, *prev = NULL;
        
        while(curr){
            Node* thread = curr->left;
            
            if(!thread){
                if(!head) head = curr;
                prev = curr;
                
                curr = curr->right;
                continue;
            }
            
            while(thread->right) thread = thread->right;
            thread->right = curr;
            

            thread = curr->left;
            if(prev) prev->right = thread;
            
            curr->left = NULL;
            curr = thread;
        }
        
        return head;
    }
    
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna