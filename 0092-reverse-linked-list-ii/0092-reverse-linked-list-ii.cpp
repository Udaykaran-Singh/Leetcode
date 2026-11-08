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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || head == NULL) return head;

        
        if(left == 1){
            ListNode* prev = NULL, * curr = head, * next = NULL;

            for(int i = 0; i < right - left + 1; i++){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            head->next = curr;

            head = prev;
        }
        else{
            ListNode* prev = head, * curr = NULL, * next = NULL;
            ListNode* just_before = NULL;

            for(int i = 1; i < left - 1; i++){
                prev = prev->next;
            }

            just_before = prev;
            curr = prev->next;

            for(int i = 0; i < right - left + 1; i++){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            just_before->next->next = curr;
            just_before->next = prev;
        }
        
        
        return head;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna