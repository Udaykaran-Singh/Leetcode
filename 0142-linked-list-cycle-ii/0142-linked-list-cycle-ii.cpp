/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* fast = head, * slow = head;

        while(fast != NULL && fast->next != NULL && slow != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow) break;
        }

        if(fast != slow) return NULL;

        slow = head;

        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna