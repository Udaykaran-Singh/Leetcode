/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        
        Node* pointer = head;

        while(pointer){
            Node* temp = new Node(pointer->val);
            temp->next = pointer->next;
            pointer->next = temp;
            pointer = temp->next;
        }

        pointer = head;

        while(pointer){
            if(pointer->random) pointer->next->random = pointer->random->next;
            pointer = pointer->next->next;
        }
        
        pointer = head->next;
        Node* ans = pointer;
        Node* real = head;
        while(pointer){
            real->next = pointer->next;
            real = real->next;
            if(real) pointer->next = real->next;
            pointer = pointer->next;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna