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
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        Node* curr = root;

        while(curr){

            if(curr->data < key){
                pre = curr;
                curr = curr->right;
            }
            else if(curr->data > key){
                suc = curr;
                curr = curr->left;
            }
            else {
                Node* temp = curr->left;
                while(temp){
                    pre = temp;
                    temp = temp->right;
                }

                temp = curr->right;
                while(temp){
                    suc = temp;
                    temp = temp->left;
                }

                break;
            }
        }

        return {pre, suc};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna