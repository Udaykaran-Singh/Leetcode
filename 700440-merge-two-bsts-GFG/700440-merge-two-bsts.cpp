/* Structure of a Binary Search Tree node
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
}; */

class Solution {
    
    void inorder(Node* root, vector<int>& arr){
        if(!root) return;
        
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    
    vector<int> mergeArrays(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        int i = 0, j = 0;

        while(i < arr1.size() && j < arr2.size()){
            if(arr1[i] <= arr2[j]){
                result.push_back(arr1[i++]);
            } 
            else{
                result.push_back(arr2[j++]);
            }
        }

        while(i < arr1.size()) result.push_back(arr1[i++]);
        while(j < arr2.size()) result.push_back(arr2[j++]);

        return result;
    }
    
  public:
    vector<int> merge(Node *root1, Node *root2) {
        // code here
        vector<int> arr1, arr2;

        inorder(root1, arr1);
        inorder(root2, arr2);

        return mergeArrays(arr1, arr2);
        
    }
};



// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna