/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {

    struct Info {
        bool isBST;
        int size;
        long long minVal, maxVal;

        Info(bool b, int s, long long mn, long long mx) {
            isBST = b;
            size = s;
            minVal = mn;
            maxVal = mx;
        }
    };

    Info solve(Node* root) {
        if (!root) return Info(true, 0, LLONG_MAX, LLONG_MIN);

        Info left = solve(root->left);
        Info right = solve(root->right);

        if (left.isBST && right.isBST && root->data > left.maxVal && root->data < right.minVal) {

            int currSize = left.size + right.size + 1;

            long long currMin = min((long long)root->data, left.minVal);
            long long currMax = max((long long)root->data, right.maxVal);

            return Info(true, currSize, currMin, currMax);
        }

        return Info(false, max(left.size, right.size), 0, 0);
    }

public:
    int largestBst(Node* root) {
        return solve(root).size;
    }
};




// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna