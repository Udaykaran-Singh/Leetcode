/*
Definition for Node
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
  public:
    vector<int> bottomView(Node *root) {
        // code here
                vector<int> ans;
                if(!root) return ans;

                map<int, int> map;
                queue<pair<Node*, int>> q;

                q.push(make_pair(root, 0));

                while(!q.empty()){
                    Node* temp = q.front().first;
                    int width = q.front().second;

                    q.pop();

                    map[width] = temp->data;

                    if(temp->left) q.push(make_pair(temp->left, width - 1));
                    if(temp->right) q.push(make_pair(temp->right, width + 1));
                }

                for(auto i : map){
                    ans.push_back(i.second);
                }

                return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna