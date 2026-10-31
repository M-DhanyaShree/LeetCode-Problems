class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        ListNode* p1=head;
        ListNode* p2=head;
        int i;
        for(i=0;i<n;i++) p1=p1->next;
        if(p1==NULL) return head->next;
        while(p1->next!=NULL) {
            p1=p1->next;
            p2=p2->next;
        }
        p2->next=p2->next->next;
        return head;
    }
};