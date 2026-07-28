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
    ListNode*reverse(ListNode*head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode*nd=reverse(head->next);
        ListNode*front=head->next;
        front->next=head;
        head->next = NULL;
        return nd;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL) {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode*nh=reverse(slow->next);
        ListNode*first=head;
        ListNode*second=nh;
        while(second!=NULL) {
            if(second->val!=first->val) {
                slow->next=reverse(nh);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        slow->next=reverse(nh);
        return true;
    }
};