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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head;

        while(fast !=NULL && fast->next !=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* prev=slow;
        slow=slow->next;
        prev->next=NULL;

        ListNode* next=NULL;

        while(slow!=NULL){
            next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }

        fast=head;
        slow=prev;
        while(slow!=NULL){
            if(fast->val != slow->val)return false;
            else{
                fast=fast->next; 
                slow=slow->next;}
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna