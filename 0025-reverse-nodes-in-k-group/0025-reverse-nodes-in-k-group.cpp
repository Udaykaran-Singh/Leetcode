/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLL(ListNode* head, ListNode* jump){
        ListNode *curr = head, *prev = jump, *next = NULL;
        while(curr != jump){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* solve(ListNode* head, int k){
        ListNode *jump = head, *newHead = head, *prev = NULL;
        int cnt = 0;

        while(jump && cnt < k){
            prev = jump;
            jump = jump->next;
            cnt++;
            if(cnt == k){
                newHead = solve(jump, k);
                prev->next = newHead;
                newHead = reverseLL(head, newHead);
            }
        }

        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        return solve(head, k);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna