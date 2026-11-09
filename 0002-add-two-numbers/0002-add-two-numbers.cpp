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
    // ListNode* reverse(ListNode* curr){
    //     ListNode *prev = NULL, *next = NULL;

    //     while(curr){
    //         next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //     }

    //     return prev;
    // }

    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        // ListNode *head1 = reverse(l1);
        // ListNode *head2 = reverse(l2);
        
        ListNode *tempHead = new ListNode(0);
        ListNode *ans = tempHead;

        int carry = 0;
        while(head1 || head2 || carry){
            int sum = carry;

            if(head1){
                sum += head1->val;
                head1 = head1->next;
            }
            if(head2){
                sum += head2->val;
                head2 = head2->next;
            }

            tempHead->next = new ListNode(sum%10);
            tempHead = tempHead->next;
            carry = sum/10;
        }

        return ans->next;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna